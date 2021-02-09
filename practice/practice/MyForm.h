#pragma once
#include "WebForm.h"
#include <fstream>
using namespace System::IO;
namespace practice {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button5;







	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(953, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(90, 30);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Выход";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(58, 46);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(240, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(512, 462);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 30);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Сохранить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"MV Boli", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(55, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(415, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Введите через пробел количество столбцов и строк массива:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::msg1);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(55, 92);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(196, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Введите элементы массива:";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(362, 40);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(118, 30);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Загрузить из файла";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(58, 111);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(334, 174);
			this->dataGridView1->TabIndex = 7;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(512, 46);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(476, 410);
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(509, 12);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(256, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Вывод массива (начальный и отсортированный):";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Vladimir Script", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(55, 303);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(184, 16);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Отсортированный массив:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(58, 322);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(334, 128);
			this->textBox2->TabIndex = 14;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(888, 462);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(100, 30);
			this->button5->TabIndex = 15;
			this->button5->Text = L"Открыть отчет";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1055, 535);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { Close(); }//close
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) { String^ string1 = textBox1->Text; }
	private: System::Void msg1(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {}
	private: System::Void dataGridView2_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) { }
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		array<String^>^ cr = textBox1->Text->Split(' ');
		dataGridView1->RowCount = Int32::Parse(cr[1]);//считываем размерность Int32::Parse переводит инт в стринг
		dataGridView1->ColumnCount = Int32::Parse(cr[0]);
		int count = dataGridView1->RowCount * dataGridView1->ColumnCount;
		System::String^ a;
		int* mas = new int[count];
		int** A = new int* [dataGridView1->RowCount];
		for (int i = 0; i < dataGridView1->RowCount; i++) {
			A[i] = new int[dataGridView1->ColumnCount];
			for (int j = 0; j < dataGridView1->ColumnCount; j++) {
				A[i][j] = 0;
			}
		}
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
		openFileDialog1->Filter = "Txt files (*.txt)|*.txt|All files (*.*)|*.*";
		if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) {
			a = File::ReadAllText(openFileDialog1->FileName);
			cr = a->Split(' ');
			for (int i = 0, k = 0; i < dataGridView1->RowCount; i++) {
				for (int j = 0; j < dataGridView1->ColumnCount; j++, k++) {
					A[i][j] = Int32::Parse(cr[k]);
					mas[k] = Int32::Parse(cr[k]);
					dataGridView1->Rows[i]->Cells[j]->Value = A[i][j];
				}
			}
		}
		for (int i = 0, k = dataGridView1->ColumnCount - 1; i < count; i++) {
			textBox1->Text += mas[i] + " ";
			if (i == k) {
				textBox1->Text += Environment::NewLine;
				k += dataGridView1->ColumnCount;
			}
		}
		Bitmap^ bm = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
		pictureBox1->Image = bm;
		Graphics^ G = Graphics::FromImage(bm);
		String^ str = ""; int p = 1;
		G->Clear(SystemColors::Window);
		for (int i = 0, k = dataGridView1->ColumnCount; i < dataGridView1->RowCount; i++) {
			for (int j = 0; j < dataGridView1->ColumnCount; j++, k++) {
				str = str->Format(str + "{0}", A[i][j] + " ");
			}
			G->DrawString(str, gcnew System::Drawing::Font("Arial", 13), Brushes::Black, Point(0, p));
			p += 15;
			str = "";
			k += dataGridView1->ColumnCount;
		}
		str = ""; p += 20;
		int step = count;
		while (step /= 2)
		{
			for (int j = 0; j < dataGridView1->ColumnCount; j++)
			{
				for (int i = 0; i < dataGridView1->RowCount; i++)
				{
					if (j + step < dataGridView1->ColumnCount)
					{
						if (A[i][j] > A[i][j + step])
						{
							int buf = A[i][j];
							A[i][j] = A[i][j + step];
							A[i][j + step] = buf;
						}
					}
					else
					{
						int s = j + step;
						int k = i;
						while (s >= dataGridView1->ColumnCount)
						{
							s -= dataGridView1->ColumnCount;
							k++;
						}
						if (k < dataGridView1->RowCount) {
							if (A[i][j] > A[k][s])
							{
								int buf = A[i][j];
								A[i][j] = A[k][s];
								A[k][s] = buf;
							}
						}
					}
				}
			}

			str = ""; p += 20;
			for (int i = 0; i < dataGridView1->RowCount; i++) {
				for (int j = 0; j < dataGridView1->ColumnCount; j++) {
					str = str->Format(str + "{0}", A[i][j] + " ");
				}
				G->DrawString(str, gcnew System::Drawing::Font("Arial", 13), Brushes::Black, Point(0, p));
				p += 15;
				str = "";
			}
		}

		for (int i = 0; i < dataGridView1->RowCount; i++) {
			for (int j = 0; j < dataGridView1->ColumnCount; j++) {
				textBox2->Text += A[i][j] + " ";
			}
			textBox2->Text += Environment::NewLine;
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
		saveFileDialog->Title = "Сохранить текст";
		saveFileDialog->Filter = "(*.txt)|*.txt";
		if (saveFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
			for (int i = 0; i < dataGridView1->RowCount; i++) {
				for (int j = 0; j < dataGridView1->ColumnCount; j++) {
					File::WriteAllText(saveFileDialog->FileName, textBox2->Text);
				}
			}
		}
		SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
		saveFileDialog1->Title = "Сохранить изображение";
		saveFileDialog1->Filter = "(*.Jpeg)|*.Jpeg";
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			pictureBox1->Image->Save(saveFileDialog1->FileName, System::Drawing::Imaging::ImageFormat::Jpeg);
		}
	}
	private: System::Void webBrowser1_DocumentCompleted(System::Object^ sender, System::Windows::Forms::WebBrowserDocumentCompletedEventArgs^ e) {
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		FileDialog^ openDialog = gcnew OpenFileDialog();
		openDialog->Title = "Открыть изображение для HTML-отчёта";
		openDialog->Filter = "Image Files (*.BMP;*.JPG;*.GIF;*.PNG;*.JPEG)|*.BMP;*JPG;*.GIF;*.PNG;*JPEG|All Files (*.*)|*.*";
		openDialog->ShowDialog();

		StreamWriter^ writer = gcnew StreamWriter("report.html");
		writer->WriteLine("<!DOCTYPE html><html><head></head><body>\n");
		writer->WriteLine("Massive sort (Shell).\n Before: "+ textBox1->Text + "\n");
		writer->WriteLine("After: " + textBox2->Text + "\n Steps:");
		writer->WriteLine("<img src=" + openDialog->FileName + "\n alt=""ИЗОБРАЖЕНИЕ НЕ НАЙДЕНО"">");
		writer->WriteLine("</body></html>");

		writer->Close();

		String^ FullPath = Path::GetFullPath("report.html");
		WebForm^ form = gcnew WebForm(FullPath);
		form->Show();
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
