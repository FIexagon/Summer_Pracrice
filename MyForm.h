#pragma once
#include < string >
#include < iostream >
#include <windows.h>


namespace shifr {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text;
	using namespace System::IO;
	using namespace System::Diagnostics;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button3;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>

		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(41, 47);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(361, 191);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(469, 47);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(361, 191);
			this->textBox2->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(508, 269);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(129, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Кодировать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(668, 269);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(129, 23);
			this->button2->TabIndex = 2;
			this->button2->TabStop = false;
			this->button2->Text = L"Раскодировать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(162, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(89, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Исходный текст";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(634, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Результат";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Выберите метош шифрования", L"Атбаш", L"Шифр Цезаря",
					L"Шифр Виженера", L"Квадрат Полибия", L"Шифр Плейфера"
			});
			this->comboBox1->Location = System::Drawing::Point(117, 308);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(201, 21);
			this->comboBox1->TabIndex = 6;
			this->comboBox1->Text = L"Выберите метош шифрования";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Lucida Console", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(41, 269);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(361, 23);
			this->textBox3->TabIndex = 0;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(61, 253);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(327, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Кодовое слово или фраза (для шифров Виженера и Плейфера)";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(590, 359);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(863, 495);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		System::Text::Encoding^ kodirovka = System::Text::Encoding::GetEncoding(1251);
		IO::StreamWriter^ sw = gcnew IO::StreamWriter("list.txt", false, kodirovka);
		sw->Write(textBox1->Text);
		sw->Close();
		int index = comboBox1->SelectedIndex;
		switch (index)
		{
		case 1:
		{
			Process^ myProcess = gcnew Process();
			myProcess->StartInfo->FileName = "Atbash.exe";
			myProcess->Start();
			System::Threading::Thread::Sleep(1000);
			IO::StreamReader^ ch = gcnew IO::StreamReader("output.txt", kodirovka);
			String^ line1;
			int k = 0;
			while ((line1 = ch->ReadLine()) != nullptr)
			{
				textBox2->Text = gcnew System::String(line1);
				k++;
			}
			ch->Close();
			break;
		}
		case 2:
		{
			Process^ myProcess = gcnew Process();
			myProcess->StartInfo->FileName = "Cezar.exe";
			myProcess->Start();
			System::Threading::Thread::Sleep(1000);
			System::Text::Encoding^ kodirovka = System::Text::Encoding::GetEncoding(1251);
			IO::StreamReader^ ch = gcnew IO::StreamReader("output.txt", kodirovka);
			String^ line1;
			int k = 0;
			while ((line1 = ch->ReadLine()) != nullptr)
			{
				textBox2->Text = gcnew System::String(line1);
				k++;
			}
			ch->Close();
			break;
		}
		case 3:
		{
			Process^ myProcess = gcnew Process();
			myProcess->StartInfo->FileName = "Vizener.exe";
			myProcess->Start();
			System::Threading::Thread::Sleep(1000);
			System::Text::Encoding^ kodirovka = System::Text::Encoding::GetEncoding(1251);
			IO::StreamReader^ ch = gcnew IO::StreamReader("output.txt", kodirovka);
			String^ line1;
			int k = 0;
			while ((line1 = ch->ReadLine()) != nullptr)
			{
				textBox2->Text = gcnew System::String(line1);
				k++;
			}
			ch->Close();
			break;
		}
		case 4:
		{
			Process^ myProcess = gcnew Process();
			myProcess->StartInfo->FileName = "Polibiy.exe";
			myProcess->Start();
			System::Threading::Thread::Sleep(1000);
			System::Text::Encoding^ kodirovka = System::Text::Encoding::GetEncoding(1251);
			IO::StreamReader^ ch = gcnew IO::StreamReader("output.txt", kodirovka);
			String^ line1;
			int k = 0;
			while ((line1 = ch->ReadLine()) != nullptr)
			{
				textBox2->Text = gcnew System::String(line1);
				k++;
			}
			ch->Close();
			break;
		}
		case 5:
		{
			IO::StreamWriter^ cd = gcnew IO::StreamWriter("code.txt", false, kodirovka);
			cd->Write(textBox3->Text);
			cd->Close();
			Process^ myProcess = gcnew Process();
			myProcess->StartInfo->FileName = "Pleyfer.exe";
			myProcess->Start();
			System::Threading::Thread::Sleep(2000);
			System::Text::Encoding^ kodirovka = System::Text::Encoding::GetEncoding(1251);
			IO::StreamReader^ ch = gcnew IO::StreamReader("output.txt", kodirovka);
			String^ line1;
			int k = 0;
			while ((line1 = ch->ReadLine()) != nullptr)
			{
				textBox2->Text = gcnew System::String(line1);
				k++;
			}
			ch->Close();
			break;
		}
		default:
		{
			textBox2->Text = "Выберите метод шифрования";;
		}
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		System::Text::Encoding^ kodirovka = System::Text::Encoding::GetEncoding(1251);
		IO::StreamWriter^ sw = gcnew IO::StreamWriter("list.txt", false, kodirovka);
		sw->Write(textBox1->Text);
		sw->Close();
		int index = comboBox1->SelectedIndex;
		switch (index)
		{
		case 1:
		{
			Process^ myProcess = gcnew Process();
			myProcess->StartInfo->FileName = "Atbash.exe";
			myProcess->Start();
			System::Threading::Thread::Sleep(1000);
			System::Text::Encoding^ kodirovka = System::Text::Encoding::GetEncoding(1251);
			IO::StreamReader^ ch = gcnew IO::StreamReader("output.txt", kodirovka);
			String^ line1;
			int k = 0;
			while ((line1 = ch->ReadLine()) != nullptr)
			{
				textBox2->Text = gcnew System::String(line1);
				k++;
			}
			ch->Close();
			break;
		}
		case 2:
		{
			Process^ myProcess = gcnew Process();
			myProcess->StartInfo->FileName = "Cezardesh.exe";
			myProcess->Start();
			System::Threading::Thread::Sleep(1000);
			System::Text::Encoding^ kodirovka = System::Text::Encoding::GetEncoding(1251);
			IO::StreamReader^ ch = gcnew IO::StreamReader("output.txt", kodirovka);
			String^ line1;
			int k = 0;
			while ((line1 = ch->ReadLine()) != nullptr)
			{
				textBox2->Text = gcnew System::String(line1);
				k++;
			}
			ch->Close();
			break;
		}
		case 3:
		{
			Process^ myProcess = gcnew Process();
			myProcess->StartInfo->FileName = "Vizenerdesh.exe";
			myProcess->Start();
			System::Threading::Thread::Sleep(1000);
			System::Text::Encoding^ kodirovka = System::Text::Encoding::GetEncoding(1251);
			IO::StreamReader^ ch = gcnew IO::StreamReader("output.txt", kodirovka);
			String^ line1;
			int k = 0;
			while ((line1 = ch->ReadLine()) != nullptr)
			{
				textBox2->Text = gcnew System::String(line1);
				k++;
			}
			ch->Close();
			break;
		}
		case 4:
		{
			Process^ myProcess = gcnew Process();
			myProcess->StartInfo->FileName = "Polibiydesh.exe";
			myProcess->Start();
			System::Threading::Thread::Sleep(1000);
			System::Text::Encoding^ kodirovka = System::Text::Encoding::GetEncoding(1251);
			IO::StreamReader^ ch = gcnew IO::StreamReader("output.txt", kodirovka);
			String^ line1;
			int k = 0;
			while ((line1 = ch->ReadLine()) != nullptr)
			{
				textBox2->Text = gcnew System::String(line1);
				k++;
			}
			ch->Close();
			break;
		}
		case 5:
		{
			IO::StreamWriter^ cd = gcnew IO::StreamWriter("code.txt", false, kodirovka);
			cd->Write(textBox3->Text);
			cd->Close();
			Process^ myProcess = gcnew Process();
			myProcess->StartInfo->FileName = "Pleyferdesh.exe";
			myProcess->Start();
			System::Threading::Thread::Sleep(2000);
			System::Text::Encoding^ kodirovka = System::Text::Encoding::GetEncoding(1251);
			IO::StreamReader^ ch = gcnew IO::StreamReader("output.txt", kodirovka);
			String^ line1;
			int k = 0;
			while ((line1 = ch->ReadLine()) != nullptr)
			{
				textBox2->Text = gcnew System::String(line1);
				k++;
			}
			ch->Close();
			break;
		}
		default:
		{
			textBox2->Text = "Выберите метод шифрования";;
		}
		}
	}
	private: System::Void hScrollBar1_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
	}
	private: System::Void vScrollBar1_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
