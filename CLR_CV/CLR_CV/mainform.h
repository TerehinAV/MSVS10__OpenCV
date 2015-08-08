#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <vector>


int Compare(const void* x1, const void* x2)
{
	return *(UCHAR*)x1 - *(UCHAR*)x2;
}

namespace CLR_CV {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для mainform
	/// </summary>
	public ref class mainform : public System::Windows::Forms::Form
	{
	public:
		mainform(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		Bitmap^ imageBitmap;
		Bitmap^ imageBin;
		Bitmap^ imageGray;
		Bitmap^ imageSmooth;
		Bitmap^ imageSmoothMedian;
		Bitmap^ imageSmoothLinear;
		Bitmap^ imageSmoothSobel;
		Bitmap^ imageContour;
		Bitmap^ imageContourBug;
		Bitmap^ imageContourScan;
		Bitmap^ imageContourLane;

		int height, width;


	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::PictureBox^  pictureBox8;
	private: System::Windows::Forms::PictureBox^  pictureBox9;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::HScrollBar^  hScrollBar1;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;



	public:
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	public:

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~mainform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::PictureBox^  pictureBox6;
	private: System::Windows::Forms::PictureBox^  pictureBox5;

	private: System::Windows::Forms::PictureBox^  pictureBox4;


	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button4;


	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(mainform::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->hScrollBar1 = (gcnew System::Windows::Forms::HScrollBar());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(12, 294);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(800, 323);
			this->tabControl1->TabIndex = 6;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->hScrollBar1);
			this->tabPage1->Controls->Add(this->button6);
			this->tabPage1->Controls->Add(this->button5);
			this->tabPage1->Controls->Add(this->button4);
			this->tabPage1->Controls->Add(this->pictureBox6);
			this->tabPage1->Controls->Add(this->pictureBox5);
			this->tabPage1->Controls->Add(this->pictureBox4);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(792, 297);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Фильтрация";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(84, 11);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 13);
			this->label2->TabIndex = 22;
			this->label2->Text = L"Маска";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(214, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(13, 13);
			this->label1->TabIndex = 21;
			this->label1->Text = L"5";
			// 
			// hScrollBar1
			// 
			this->hScrollBar1->LargeChange = 2;
			this->hScrollBar1->Location = System::Drawing::Point(130, 8);
			this->hScrollBar1->Maximum = 16;
			this->hScrollBar1->Minimum = 3;
			this->hScrollBar1->Name = L"hScrollBar1";
			this->hScrollBar1->Size = System::Drawing::Size(80, 17);
			this->hScrollBar1->SmallChange = 2;
			this->hScrollBar1->TabIndex = 20;
			this->hScrollBar1->Value = 5;
			// 
			// button6
			// 
			this->button6->Enabled = false;
			this->button6->Location = System::Drawing::Point(530, 6);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 19;
			this->button6->Text = L"Собеля";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &mainform::button6_Click);
			// 
			// button5
			// 
			this->button5->Enabled = false;
			this->button5->Location = System::Drawing::Point(268, 6);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 18;
			this->button5->Text = L"Линейный";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &mainform::button5_Click);
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(6, 6);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 10;
			this->button4->Text = L"Медианный";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &mainform::button4_Click);
			// 
			// pictureBox6
			// 
			this->pictureBox6->Location = System::Drawing::Point(530, 35);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(256, 256);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox6->TabIndex = 17;
			this->pictureBox6->TabStop = false;
			this->pictureBox6->Click += gcnew System::EventHandler(this, &mainform::pictureBox6_Click);
			// 
			// pictureBox5
			// 
			this->pictureBox5->Location = System::Drawing::Point(268, 35);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(256, 256);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox5->TabIndex = 16;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Click += gcnew System::EventHandler(this, &mainform::pictureBox5_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(6, 35);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(256, 256);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 15;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Click += gcnew System::EventHandler(this, &mainform::pictureBox4_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->button7);
			this->tabPage2->Controls->Add(this->button8);
			this->tabPage2->Controls->Add(this->button9);
			this->tabPage2->Controls->Add(this->pictureBox7);
			this->tabPage2->Controls->Add(this->pictureBox8);
			this->tabPage2->Controls->Add(this->pictureBox9);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(792, 297);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Контуры";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Enabled = false;
			this->button7->Location = System::Drawing::Point(6, 6);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 23);
			this->button7->TabIndex = 25;
			this->button7->Text = L"Жук";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &mainform::button7_Click);
			// 
			// button8
			// 
			this->button8->Enabled = false;
			this->button8->Location = System::Drawing::Point(268, 6);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 23);
			this->button8->TabIndex = 24;
			this->button8->Text = L"Перебор";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &mainform::button8_Click);
			// 
			// button9
			// 
			this->button9->Enabled = false;
			this->button9->Location = System::Drawing::Point(530, 6);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(75, 23);
			this->button9->TabIndex = 20;
			this->button9->Text = L"Сканирующий";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &mainform::button9_Click);
			// 
			// pictureBox7
			// 
			this->pictureBox7->Location = System::Drawing::Point(6, 35);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(256, 256);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox7->TabIndex = 23;
			this->pictureBox7->TabStop = false;
			// 
			// pictureBox8
			// 
			this->pictureBox8->Location = System::Drawing::Point(268, 35);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(256, 256);
			this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox8->TabIndex = 22;
			this->pictureBox8->TabStop = false;
			// 
			// pictureBox9
			// 
			this->pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.Image")));
			this->pictureBox9->Location = System::Drawing::Point(530, 35);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(256, 256);
			this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox9->TabIndex = 21;
			this->pictureBox9->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(22, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Загрузить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &mainform::button1_Click);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(103, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Серое";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &mainform::button2_Click);
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(184, 3);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Отсу";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &mainform::button3_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(22, 32);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(256, 256);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 15;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(284, 32);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(256, 256);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 16;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(546, 32);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(256, 256);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 17;
			this->pictureBox3->TabStop = false;
			// 
			// button10
			// 
			this->button10->Enabled = false;
			this->button10->Location = System::Drawing::Point(546, 3);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(96, 23);
			this->button10->TabIndex = 21;
			this->button10->Text = L"Сохранить все";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &mainform::button10_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(722, 3);
			this->progressBar1->Maximum = 9;
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(80, 23);
			this->progressBar1->Step = 1;
			this->progressBar1->TabIndex = 22;
			// 
			// mainform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(821, 625);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tabControl1);
			this->Name = L"mainform";
			this->Text = L"mainform";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pictureBox4_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void pictureBox5_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void pictureBox6_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
//open
			 if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 this->Text = openFileDialog1->FileName;
				 this->pictureBox1->Load(openFileDialog1->FileName);

				 width = pictureBox1->Image->Width;
				 height = pictureBox1->Image->Height;

				 String^ h = Convert::ToString(height);
				 String^ w = Convert::ToString(width);;

				 imageBitmap = gcnew Bitmap(pictureBox1->Image);
				 button2->Enabled = true;
				 button3->Enabled = false;
				 button4->Enabled = false;
				 button5->Enabled = false;
				 button6->Enabled = false;
				 button7->Enabled = true;
				 button8->Enabled = true;
				 button9->Enabled = true;

			 }



}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
//gray
			 imageGray = gcnew Bitmap(pictureBox1->Image);
			 for (int i = 0; i < width; i++)
			 for (int j = 0; j < height; j++)
			 {
				 Color pixelColour = imageBitmap->GetPixel(i, j);
				 float S, R, G, B;

				 R = pixelColour.R;
				 G = pixelColour.G;
				 B = pixelColour.B;

				 S = (R*0.299 + G*0.587 + B*0.114);

				 imageGray->SetPixel(i, j, Color::FromArgb(255, S, S, S));


			 }
			 pictureBox2->Image = imageGray;
			 button2->Enabled = false;
			 button3->Enabled = true;
			 button4->Enabled = true;
			 button5->Enabled = true;
			 button6->Enabled = true;
			 button10->Enabled = true;



}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
//bin
			 int hist[256] = { 0 };
			 int min = 0;
			 int max = min;

			 imageBin = gcnew Bitmap(pictureBox2->Image);
			 for (int y = 0; y < height; ++y)
			 {
				 for (int x = 0; x < width; ++x)
				 {
					 int val = imageBin->GetPixel(x, y).R;
					 ++hist[val];

					 if (val < min)
						 min = val;
					 else if (val > max)
						 max = val;
				 }
			 }

			 int m = 0;
			 int n = width * height;

			 for (int i = 0; i <= max - min; ++i)
				 m += i * hist[i + min];

			 int alpha = 0;
			 int beta = 0;
			 double w;
			 double a;
			 double sigma;
			 double sigma_max = 0;
			 int threshold = 0;

			 for (int i = 0; i < max - min; ++i)
			 {
				 alpha += i * hist[i + min];
				 beta += hist[i + min];

				 w = (double)beta / n;
				 a = (double)alpha / beta - (double)(m - alpha) / (n - beta);
				 sigma = w * (1 - w) * a * a;

				 if (sigma > sigma_max)
				 {
					 sigma_max = sigma;
					 threshold = i;
				 }
			 }

			 threshold += min;

			 for (int y = 0; y < height; ++y)
			 {
				 for (int x = 0; x < width; ++x)
				 {
					 if (imageBin->GetPixel(x, y).R > threshold)
						 imageBin->SetPixel(x, y, Color::FromArgb(255, 255, 255, 255));
					 else
						 imageBin->SetPixel(x, y, Color::FromArgb(255, 0, 0, 0));
				 }
			 }
			 pictureBox3->Image = imageBin;
			 button7->Enabled = true;
			 button8->Enabled = true;
			 button9->Enabled = true;

}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 int mask_size = Convert::ToInt64(label1->Text);
			 size_t val_amount = mask_size * mask_size;
			 UCHAR* values = new UCHAR[val_amount];
			 imageSmooth = gcnew Bitmap(pictureBox2->Image);
			 imageSmoothMedian = gcnew Bitmap(pictureBox2->Image);

			 for (int r = mask_size / 2; r < height - (mask_size / 2) - 1; ++r)
			 {
				 for (int c = mask_size / 2; c < width - (mask_size / 2) - 1; ++c)
				 {
					 int idx = 0;

					 for (int j = 0; j < mask_size; ++j)
					 {
						 for (int i = 0; i < mask_size; ++i)
						 {
							 values[idx++] = UCHAR(imageSmooth->GetPixel((c + j - mask_size / 2), (r + i - mask_size / 2)).R);
						 }
					 }
					 qsort(values, val_amount, sizeof(UCHAR), Compare);

					 imageSmoothMedian->SetPixel(c, r, Color::FromArgb(255, values[val_amount / 2], values[val_amount / 2], values[val_amount / 2]));
				 }
			 }
			 pictureBox4->Image = imageSmoothMedian;
			 //->Image->Save("Median.Bmp");
			 imageSmoothMedian->Save("..\\saved\\Median.Bmp");


}
private: System::Void hScrollBar1_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
//mask
			 this->label1->Text = Convert::ToString(hScrollBar1->Value);
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
//linear
			 imageSmooth = gcnew Bitmap(pictureBox2->Image);
			 imageSmoothLinear = gcnew Bitmap(pictureBox2->Image);

			 int posR[] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
			 int posC[] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
			 int coefs[] = { 1, 2, 1, 2, 4, 2, 1, 2, 1 };
			 double norm = 16;

			 for (int r = 1; r < height - 1; ++r)
			 {
				 for (int c = 1; c < width - 1; ++c)
				 {
					 int sum = 0;

					 for (int i = 0; i < 9; ++i)
						 sum += imageSmooth->GetPixel((c + posC[i]), (r + posR[i])).R * coefs[i];

					 
					 imageSmoothLinear->SetPixel(c, r, Color::FromArgb(255, (UCHAR)round(sum / norm), (UCHAR)round(sum / norm), (UCHAR)round(sum / norm)));
				 }
			 }
			 pictureBox5->Image = imageSmoothLinear;

}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
//sobel

			 imageSmooth = gcnew Bitmap(pictureBox2->Image);
			 imageSmoothSobel = gcnew Bitmap(pictureBox2->Image);

			 for (int r = 1; r < height - 1; ++r)
			 {
				 for (int c = 1; c < width - 1; ++c)
				 {
					 int temp = (int)round(sqrt(pow(-1 * imageSmooth->GetPixel(c - 1, r - 1).R - 2 * imageSmooth->GetPixel(c, r - 1).R - imageSmooth->GetPixel(c + 1, r - 1).R +
						 imageSmooth->GetPixel(c - 1, r + 1).R + 2 * imageSmooth->GetPixel(c, r + 1).R + imageSmooth->GetPixel(c + 1, r + 1).R, 2)
						 +
						 pow(-1 * imageSmooth->GetPixel(c - 1, r - 1).R + imageSmooth->GetPixel(c + 1, r - 1).R +
						 -2 * imageSmooth->GetPixel(c - 1, r).R + 2 * imageSmooth->GetPixel(c + 1, r).R -
						 imageSmooth->GetPixel(c - 1, r + 1).R + imageSmooth->GetPixel(c + 1, r + 1).R, 2)));
					 if (temp > 255)
						 temp = 255;
					 imageSmoothSobel->SetPixel(c, r, Color::FromArgb(255, (temp + imageSmooth->GetPixel(c, r).R) / 2, (temp + imageSmooth->GetPixel(c, r).R) / 2, (temp + imageSmooth->GetPixel(c, r).R) / 2));
					 					 					 
				 }
			 }
			 pictureBox6->Image = imageSmoothSobel;


}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
//scan
//clear white
			 imageContour = gcnew Bitmap(pictureBox3->Image);
			 imageContourScan = gcnew Bitmap(pictureBox3->Image);
			 for (int r = 0; r < height; ++r)
			 {
				 for (int c = 0; c < width - 1; ++c)
				 {
					 imageContourScan->SetPixel(c , r, Color::FromArgb(255, 255, 255, 255));
				 }
			 }

//scan horiz
			 for (int r = 1; r < height; ++r)
			 {
				 for (int c = 1; c < width - 1; ++c)
				 {
					 if ((imageContour->GetPixel(c - 1, r).R == 255 && imageContour->GetPixel(c, r).R == 0) ||
						 (imageContour->GetPixel(c + 1, r).R == 255 && imageContour->GetPixel(c, r).R == 0))

						 imageContourScan->SetPixel(c , r, Color::FromArgb(255, 0, 0, 0));				 
				 }
			 }

//scan vert
			 for (int c = 1; c < width; ++c)
			 {
				 for (int r = 1; r < height - 1; ++r)
				 {

					 if ((imageContour->GetPixel(c, r - 1).R == 255 && imageContour->GetPixel(c, r).R == 0) ||
						 (imageContour->GetPixel(c, r + 1).R == 255 && imageContour->GetPixel(c, r).R == 0))

						 imageContourScan->SetPixel(c, r, Color::FromArgb(255, 0, 0, 0));
				 }
			 }

			 pictureBox9->Image = imageContourScan;
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
//clear white
			 imageContour = gcnew Bitmap(pictureBox3->Image);
			 imageContourBug = gcnew Bitmap(pictureBox3->Image);
			 for (int r = 0; r < height; ++r)
			 {
				 for (int c = 0; c < width - 1; ++c)
				 {
					 imageContourBug->SetPixel(c, r, Color::FromArgb(255, 255, 255, 255));
				 }
			 }
//Bug
			 enum Direction
			 {
				 up,
				 down,
				 left,
				 right
			 };
			 int startR;
			 int startC;
			 int curR;
			 int curC;
			 Direction dir = up;
			 bool found = false;

			 for (int r = 0; r < height; ++r)
			 {
				 for (int c = 0; c < width; ++c)
				 {
					 if (imageContour->GetPixel(c, r).R == 0)
					 {
						 imageContourBug->SetPixel(c, r, Color::FromArgb(255, 0, 0, 0));
						 startR = r;
						 startC = c;
						 curR = r;
						 curC = c;
						 found = true;
						 break;
					 }
				 }

				 if (found)
					 break;
			 }

			 do
			 {
				 switch (dir)
				 {
				 case up:
					 --curR;
					 
					 if (imageContour->GetPixel(curC, curR).R == 255)
					 {
						 imageContourBug->SetPixel(curC, curR, Color::FromArgb(255, 0, 0, 0));						 
						 dir = right;
					 }
					 else
						 dir = left;

					 break;

				 case down:
					 ++curR;

					 if (imageContour->GetPixel(curC, curR).R == 255)
					 {
						 imageContourBug->SetPixel(curC, curR, Color::FromArgb(255, 0, 0, 0));
						 dir = left;
					 }
					 else
						 dir = right;

					 break;

				 case left:
					 --curC;

					 if (imageContour->GetPixel(curC, curR).R == 255)
					 {
						 imageContourBug->SetPixel(curC, curR, Color::FromArgb(255, 0, 0, 0));
						 dir = up;
					 }
					 else
						 dir = down;

					 break;

				 case right:
					 ++curC;

					 if (imageContour->GetPixel(curC, curR).R == 255)
					 {
						 imageContourBug->SetPixel(curC, curR, Color::FromArgb(255, 0, 0, 0));
						 dir = down;
					 }
					 else
						 dir = up;
				 }
			 } while (curR != startR || curC != startC);
			 pictureBox7->Image = imageContourBug;
			 
			 
}
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
//save
			 progressBar1->Value = 0;
			 if (imageBitmap) imageBitmap->Save("..\\saved\\Sourse.Bmp");
			 progressBar1->Value++;
			 if (imageBin) imageBin->Save("..\\saved\\Bin.Bmp");
			 progressBar1->Value++;
			 if (imageGray) imageGray->Save("..\\saved\\Gray.Bmp");
			 progressBar1->Value++;
			 if (imageSmoothMedian) imageSmoothMedian->Save("..\\saved\\Median.Bmp");
			 progressBar1->Value++;
			 if (imageSmoothLinear) imageSmoothLinear->Save("..\\saved\\Linear.Bmp");
			 progressBar1->Value++;
			 if (imageSmoothSobel) imageSmoothSobel->Save("..\\saved\\Sobel.Bmp");
			 progressBar1->Value++;
			 if (imageContourBug) imageContourBug->Save("..\\saved\\ContBug.Bmp");
			 progressBar1->Value++;
			 if (imageContourScan) imageContourScan->Save("..\\saved\\ContScan.Bmp");
			 progressBar1->Value++;
			 if (imageContourLane) imageContourLane->Save("..\\saved\\ContLane.Bmp");
			 progressBar1->Value++;
}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
//clear white
			 imageContour = gcnew Bitmap(pictureBox3->Image);
			 imageContourLane = gcnew Bitmap(pictureBox3->Image);
			 for (int r = 0; r < height; ++r)
			 {
				 for (int c = 0; c < width - 1; ++c)
				 {
					 imageContourLane->SetPixel(c, r, Color::FromArgb(255, 255, 255, 255));
				 }
			 }
//lane
			 int startR;
			 int startC;
			 int curR;
			 int curC;
			 bool found = false;
			 int posR[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
			 int posC[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
			 int prevP = 0;

			 for (int r = 0; r < height; ++r)
			 {
				 for (int c = 0; c < width; ++c)
				 {
					 if (imageContour->GetPixel(c, r).R == 0)
					 {
						 imageContourLane->SetPixel(c, r, Color::FromArgb(255, 0, 0, 0));
						 startR = r;
						 startC = c;
						 curR = r;
						 curC = c;
						 found = true;
						 break;
					 }
				 }

				 if (found)
					 break;
			 }

			 do
			 {
				 for (int p = 0; p < 8; ++p)
				 {
					 int curP = (p + prevP) % 8;
					 
					 if (imageContour->GetPixel(curC + posC[curP], curR + posR[curP]).R == 0)
					 {
						 curR += posR[curP];
						 curC += posC[curP];
						 imageContourLane->SetPixel(curC, curR, Color::FromArgb(255, 0, 0, 0));
						 //*cvPtr2D(dst, curR, curC) = 0;
						 prevP = (curP + 5) % 8;
						 break;
					 }
				 }
			 } while (curR != startR || curC != startC);


			 pictureBox8->Image = imageContourLane;
}
};
}
