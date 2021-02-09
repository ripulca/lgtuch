using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace kur2k
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private UIElement _lastClickedUIElement;
        private UIElement delElem;
        private Point? _clickOffset;
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Paint_surf_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            _lastClickedUIElement = sender as UIElement;
            _clickOffset = e.GetPosition(_lastClickedUIElement);
        }

        private void Paint_surf_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            _lastClickedUIElement = null;
        }

        private void Paint_surf_MouseMove(object sender, MouseEventArgs e)
        {
            if (_lastClickedUIElement == null)
                return;

            _lastClickedUIElement.SetValue(Canvas.LeftProperty, Mouse.GetPosition(this).X - _clickOffset.Value.X);
            _lastClickedUIElement.SetValue(Canvas.TopProperty, Mouse.GetPosition(this).Y - _clickOffset.Value.Y);
        }

        private void Add_btn_Click(object sender, RoutedEventArgs e)
        {
            TextInputWindow inp = new TextInputWindow();
            TextBlock text = new TextBlock();
            inp.ShowDialog();
            text.Text = inp.getName;
            text.SetValue(Canvas.LeftProperty, Convert.ToDouble(inp.getX));
            text.SetValue(Canvas.TopProperty, Convert.ToDouble(inp.getX));
            Rectangle rectangle = new Rectangle();
            rectangle.Width = 50;
            rectangle.Height = 50;
            rectangle.VerticalAlignment = VerticalAlignment.Top;
            rectangle.Fill = Brushes.White;
            rectangle.Stroke = Brushes.Black;
            rectangle.StrokeThickness = 3;
            rectangle.SetValue(Canvas.LeftProperty, Convert.ToDouble(inp.getX));
            rectangle.SetValue(Canvas.TopProperty, Convert.ToDouble(inp.getX));
            Paint_surf.Children.Add(rectangle);
            Paint_surf.Children.Add(text);
            rectangle.MouseMove += Paint_surf_MouseMove;
            rectangle.MouseLeftButtonDown += Paint_surf_MouseLeftButtonDown;
            rectangle.MouseLeftButtonUp += Paint_surf_MouseLeftButtonUp;
            rectangle.MouseRightButtonDown += Paint_surf_MouseRightButtonDown;
            text.MouseMove += Paint_surf_MouseMove;
            text.MouseLeftButtonDown += Paint_surf_MouseLeftButtonDown;
            text.MouseLeftButtonUp += Paint_surf_MouseLeftButtonUp;
            text.MouseRightButtonDown += Paint_surf_MouseRightButtonDown;
        }

        private void Clean_btn_Click(object sender, RoutedEventArgs e)
        {
            Paint_surf.Children.Clear();
        }
        private void SaveImg_btn_Click(object sender, RoutedEventArgs e)
        {
            Microsoft.Win32.SaveFileDialog saveimg = new Microsoft.Win32.SaveFileDialog();
            saveimg.DefaultExt = ".PNG";
            saveimg.Filter = "Image (.PNG)|*.PNG";
            if (saveimg.ShowDialog() == true)
            {
                RenderTargetBitmap bmp = new RenderTargetBitmap((int)Paint_surf.ActualWidth, (int)Paint_surf.ActualHeight, 96d, 96d, PixelFormats.Pbgra32);
                Paint_surf.Measure(new Size((int)Paint_surf.ActualWidth, (int)Paint_surf.ActualHeight));
                Paint_surf.Arrange(new Rect(new Size((int)Paint_surf.ActualWidth, (int)Paint_surf.ActualHeight)));
                bmp.Render(Paint_surf);
                PngBitmapEncoder encoder = new PngBitmapEncoder();
                encoder.Frames.Add(BitmapFrame.Create(bmp));
                using (var fs = System.IO.File.OpenWrite(saveimg.FileName))
                {
                    encoder.Save(fs);
                }
            }
        }

        private void Paint_surf_MouseRightButtonDown(object sender, MouseButtonEventArgs e)
        {
            delElem = sender as Rectangle;
            Paint_surf.Children.Remove(delElem);
        }

        private void SaveXaml_btn_Click(object sender, RoutedEventArgs e)
        {
            System.IO.FileStream fs = System.IO.File.Open("test.xaml", System.IO.FileMode.Create);
            System.Windows.Markup.XamlWriter.Save(Paint_surf, fs);
            fs.Close();
        }

        private void Open_btn_Click(object sender, RoutedEventArgs e)
        {
            Microsoft.Win32.OpenFileDialog opener = new Microsoft.Win32.OpenFileDialog();
            if (opener.ShowDialog() == true)
            {
                System.IO.FileStream fs = System.IO.File.Open(opener.FileName, System.IO.FileMode.Open, System.IO.FileAccess.Read);
                Canvas savedCanvas = System.Windows.Markup.XamlReader.Load(fs) as Canvas;
                fs.Close();
                this.Root.Children.Add(savedCanvas);
            }
        }
    }
}
