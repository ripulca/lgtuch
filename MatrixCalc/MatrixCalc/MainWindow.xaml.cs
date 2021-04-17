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

namespace MatrixCalc
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private static Brush CELL_COLOR_1 = Brushes.Lavender;
        private static Brush CELL_COLOR_2 = Brushes.LightGray;
        private List<TextBox> table1 = new List<TextBox>();
        private TextBox[,] table2 = new TextBox[30, 30];
        private static SolidColorBrush[] matrixBrushes = {
            Brushes.Khaki,
            Brushes.PowderBlue,
            Brushes.MistyRose,
            Brushes.Coral,
            Brushes.Peru,
            Brushes.LightSeaGreen,
            Brushes.Aquamarine,
            Brushes.AliceBlue,
            Brushes.BlanchedAlmond
        };
        List<List<float>> tmp1 = new List<List<float>>();
        List<List<float>> tmp2 = new List<List<float>>();
        List<float> tmp = new List<float>(); 
        List<List<float>> res = new List<List<float>>(); double res1 = 0;
        public MainWindow()
        {
            InitializeComponent();
            double _height = 20.0;
            double _width = 60.0;
            double _amount = 30;
            for (int i=0; i<_amount ;i++)
            {
                RowDefinition row = new RowDefinition();
                row.MinHeight = _height;
                Table.RowDefinitions.Add(row);
            }
            for (int i = 0; i < _amount; i++)
            {
                ColumnDefinition col = new ColumnDefinition();
                col.MinWidth = _width;
                Table.ColumnDefinitions.Add(col);
            }

            int rowi = 0;
            foreach (RowDefinition row in Table.RowDefinitions)
            {
                int coli = 0;
                foreach (ColumnDefinition col in Table.ColumnDefinitions)
                {
                    TextBox tb = new TextBox();
                    tb.Background = ((rowi + coli) % 2 == 0) ? CELL_COLOR_1 : CELL_COLOR_2;
                    Grid.SetRow(tb, rowi);
                    Grid.SetColumn(tb, coli);
                    tb.MouseMove += TextBoxes_MouseMove;
                    tb.KeyDown += Window_KeyDown;
                    tb.KeyUp += Window_KeyUp;
                    Table.Children.Add(tb);
                    this.table1.Add(tb);
                    coli++;
                }
                rowi++;
            }
            for (int l = 0; l < _amount; l++)
            {
                for (int j = 0; j < _amount; j++)
                {
                    table2[j, l] = table1.First();
                    table1.Remove(table1.First());
                }
            }
        }
        private void Plus_Click(object sender, RoutedEventArgs e)
        {
            int cl = tmp1[0].Count(), rw = tmp1.Count();
            if (tmp1[0].Count() > tmp2[0].Count()) { cl = tmp2[0].Count(); }
            if (tmp1.Count() > tmp2.Count()) { rw = tmp2.Count(); }
            for(int i = 0; i < rw; i++)
            {
                tmp = new List<float>();
                for (int j = 0; j < cl; j++)
                {
                    tmp.Add(tmp1[i][j] + tmp2[i][j]);
                }
                res.Add(tmp);
            }
            //CleanAll_Click(sender, e);

            Renewall();
            tmp1 = new List<List<float>>();
            tmp2 = new List<List<float>>();
            for (int i = 0; i < res.Count(); i++)
            {
                for (int j = 0; j < tmp.Count(); j++)
                {
                    table2[j, i].Text = res[i][j].ToString();
                }
            }
            res = new List<List<float>>();
        }

        private void Multiply_Click(object sender, RoutedEventArgs e)
        {
            int cl = tmp1[0].Count(); float temp=0;
            if (tmp1[0].Count() > tmp2.Count()) { cl = tmp2.Count(); }
            for (int matrix1_row = 0; matrix1_row < tmp1.Count(); matrix1_row++)
            {
                tmp = new List<float>();
                // цикл по каждому столбцу второй матрицы  
                for (int matrix2_col = 0; matrix2_col < tmp2[0].Count(); matrix2_col++)
                {
                    // вычисляем скалярное произведение двух векторов  
                    for (int matrix1_col = 0; matrix1_col < cl; matrix1_col++)
                    {
                        temp +=tmp1[matrix1_row][matrix1_col] * tmp2[matrix1_col][matrix2_col];
                    }
                    tmp.Add(temp);
                    temp = 0;
                }
                res.Add(tmp);
            }
            //CleanAll_Click(sender, e);
            Renewall();
            tmp1 = new List<List<float>>();
            tmp2 = new List<List<float>>();
            for (int i = 0; i < res.Count(); i++)
            {
                for(int j = 0; j < tmp.Count(); j++)
                {
                    table2[j, i].Text = res[i][j].ToString();
                }
            }
            res = new List<List<float>>();
        }

        private void Det_Click(object sender, RoutedEventArgs e)
        {
            if (tmp2.Count() == 0)
            {
                res1 = determenant(tmp1);
            }
            else { res1 = determenant(tmp2); }
            CleanAll_Click(sender, e);
            tmp1 = new List<List<float>>();
            tmp2 = new List<List<float>>();
            table2[0, 0].Text = "det=";
            table2[0, 1].Text = res1.ToString();
        }
        public double determenant(List<List<float>> m)
        {
            List<List<float>> minor = new List<List<float>>();
            double det = 0;
            if (m[0].Count() != m.Count())
                throw new ArgumentException("Matrix must be square");
            if (m[0].Count() == 1)
            {
                return m[0][0];
            }
            else if (m[0].Count() == 2)
            { // cols == rows
                return m[0][0] * m[1][1] - m[0][1] * m[1][0];
            }
            for (int i = 0; i < m[0].Count(); i++)
            {
                minor = getMinor(m, i);
                //m = mtmp;
                det += ((i % 2 == 1) ? -1 : 1) * m[0][i] * determenant(minor);
            }
            return det;
        }

        private List<List<float>> getMinor(List<List<float>> m, int col)
        {
            List<List<float>> mtmp = new List<List<float>>();
            List<List<float>> minor = new List<List<float>>();
            List<float> tmpmin = new List<float>();
            for (int i = 0; i < m.Count(); i++)
            {
                tmpmin = new List<float>();
                for (int j = 0; j < m[0].Count(); j++)
                {
                    tmpmin.Add(m[i][j]);
                }
                if (tmpmin.Count() != 0)
                {
                    mtmp.Add(tmpmin);
                }
            }
            for (int i = 0; i < m[0].Count(); i++)
            {
                mtmp[0][i] = float.NaN;
            }
            for(int i = 1; i < m.Count(); i++)
            {
                mtmp[i][col] = float.NaN;
            }
            for(int i = 0; i < mtmp.Count(); i++)
            {
                tmpmin = new List<float>();
                for (int j = 0; j < mtmp[0].Count(); j++)
                {
                    if (!mtmp[i][j].Equals(float.NaN))
                    {
                        tmpmin.Add(mtmp[i][j]);
                    }
                }
                if (tmpmin.Count() != 0)
                {
                    minor.Add(tmpmin);
                }
            }
            mtmp = new List<List<float>>();

            return minor;
        }

        private void Clean_Click(object sender, RoutedEventArgs e)
        {
            for (int i = 0; i < 30; i++)
            {
                for (int j = 0; j < 30; j++)
                {
                    table2[i, j].Background = ((i + j) % 2 == 0) ? CELL_COLOR_1 : CELL_COLOR_2;
                }
            }
            Renewall();
            tmp1 = new List<List<float>>();
            tmp2 = new List<List<float>>();
        }

        private bool pressedLeftMouseButton;
        int currentBrush = 0, tempbrush = 0;
        private bool[] currentRows = new bool[30];
        private bool[] currentCols = new bool[30];
        private void TextBoxes_MouseMove(object sender, MouseEventArgs e)
        {
            var cursorPosition = Mouse.GetPosition(this);
            if (!pressedLeftMouseButton) return;
            GetBrushesZone(matrixBrushes[currentBrush]);
            
        }

        private void Renewall()
        {
            for (int i = 0; i < currentCols.Length; i++) { currentCols[i] = false; }
            for (int i = 0; i < currentRows.Length; i++) { currentRows[i] = false; }
            //if (isOld) { isOld = false; } else { isOld = true; }
        }
        private void GetBrushesZone(SolidColorBrush color)
        {
            for (int i = 0; i < this.Table.ColumnDefinitions.Count(); i++)
            {
                for (int j = 0; j < this.Table.RowDefinitions.Count(); j++)
                {
                    if (table2[i, j].IsMouseOver && pressedLeftMouseButton)
                    {
                        table2[i, j].Background = color;
                        currentCols[i] = true;
                        currentRows[j] = true;
                    }
                    if (currentCols[i] && currentRows[j])
                    {
                        table2[i, j].Background = color;
                    }
                }
            }
            
        }

        private void Window_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.Key)
            {
                case Key.LeftShift:
                    pressedLeftMouseButton = true;
                    break;
            }
        }

        private void Window_KeyUp(object sender, KeyEventArgs e)
        {
            switch (e.Key)
            {
                case Key.LeftShift:
                    pressedLeftMouseButton = false;
                    break;
            }
            //isFirstArg = false;
            for (int i=0;i<30;i++)
            {
                tmp = new List<float>();
                for (int j = 0; j < 30; j++)
                {
                    if((table2[j,i].Background== matrixBrushes[currentBrush])&&(table2[j,i].Text!=""))
                    {
                        float ab = float.Parse(table2[j, i].Text);
                        tmp.Add(ab);
                    }
                }
                if (tmp.Count!=0) {
                    if ((tmp1.Count()==0)||(tempbrush==currentBrush)) {
                        tmp1.Add(tmp);
                        tempbrush = currentBrush;
                    }
                    else
                    {
                        tmp2.Add(tmp);
                    } 
                }
            }
            Renewall();
            currentBrush++;
            if (currentBrush == matrixBrushes.Length) { currentBrush = 0; }
        }

        private void CleanAll_Click(object sender, RoutedEventArgs e)
        {
            for(int i = 0; i < 30; i++)
            {
                for(int j = 0; j < 30; j++)
                {
                    table2[i, j].Text = null;
                    table2[i,j].Background= ((i + j) % 2 == 0) ? CELL_COLOR_1 : CELL_COLOR_2;
                }
            }
            Renewall();
            tmp1 = new List<List<float>>();
            tmp2 = new List<List<float>>();
        }
    }
}
