#pragma once

namespace COM_Port_cpp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	using namespace std;

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			findPorts(); 
			//findPorts();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::IO::Ports::SerialPort^  serialPort1;
	protected: 
	private: System::Windows::Forms::ComboBox^  cBoxCOMPORT;
	private: System::Windows::Forms::Button^  btnSend;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  cBoxBaudRate;
	private: System::Windows::Forms::Button^  btnOpen;
	private: System::Windows::Forms::Button^  btnClose;
	private: System::Windows::Forms::Button^  btnReciv;
	private: System::Windows::Forms::TextBox^  tBoxSend;
	private: System::Windows::Forms::TextBox^  tBoxReciv;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->cBoxCOMPORT = (gcnew System::Windows::Forms::ComboBox());
			this->btnSend = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cBoxBaudRate = (gcnew System::Windows::Forms::ComboBox());
			this->btnOpen = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnReciv = (gcnew System::Windows::Forms::Button());
			this->tBoxSend = (gcnew System::Windows::Forms::TextBox());
			this->tBoxReciv = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// cBoxCOMPORT
			// 
			this->cBoxCOMPORT->FormattingEnabled = true;
			this->cBoxCOMPORT->Location = System::Drawing::Point(87, 206);
			this->cBoxCOMPORT->Name = L"cBoxCOMPORT";
			this->cBoxCOMPORT->Size = System::Drawing::Size(121, 21);
			this->cBoxCOMPORT->TabIndex = 0;
			// 
			// btnSend
			// 
			this->btnSend->Location = System::Drawing::Point(244, 9);
			this->btnSend->Name = L"btnSend";
			this->btnSend->Size = System::Drawing::Size(75, 23);
			this->btnSend->TabIndex = 1;
			this->btnSend->Text = L"SEND";
			this->btnSend->UseVisualStyleBackColor = true;
			this->btnSend->Click += gcnew System::EventHandler(this, &Form1::btnSend_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 209);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"COM PORT";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 236);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(69, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"BAUD RATE";
			// 
			// cBoxBaudRate
			// 
			this->cBoxBaudRate->FormattingEnabled = true;
			this->cBoxBaudRate->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"4800", L"9600", L"14400", L"19200"});
			this->cBoxBaudRate->Location = System::Drawing::Point(87, 233);
			this->cBoxBaudRate->Name = L"cBoxBaudRate";
			this->cBoxBaudRate->Size = System::Drawing::Size(121, 21);
			this->cBoxBaudRate->TabIndex = 4;
			this->cBoxBaudRate->Text = L"9600";
			// 
			// btnOpen
			// 
			this->btnOpen->Location = System::Drawing::Point(244, 206);
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(75, 23);
			this->btnOpen->TabIndex = 5;
			this->btnOpen->Text = L"OPEN";
			this->btnOpen->UseVisualStyleBackColor = true;
			this->btnOpen->Click += gcnew System::EventHandler(this, &Form1::btnOpen_Click);
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(244, 233);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(75, 23);
			this->btnClose->TabIndex = 6;
			this->btnClose->Text = L"CLOSE";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &Form1::btnClose_Click);
			// 
			// btnReciv
			// 
			this->btnReciv->Location = System::Drawing::Point(244, 40);
			this->btnReciv->Name = L"btnReciv";
			this->btnReciv->Size = System::Drawing::Size(75, 23);
			this->btnReciv->TabIndex = 7;
			this->btnReciv->Text = L"RECIV";
			this->btnReciv->UseVisualStyleBackColor = true;
			this->btnReciv->Click += gcnew System::EventHandler(this, &Form1::btnReciv_Click);
			// 
			// tBoxSend
			// 
			this->tBoxSend->Location = System::Drawing::Point(18, 9);
			this->tBoxSend->Name = L"tBoxSend";
			this->tBoxSend->Size = System::Drawing::Size(220, 20);
			this->tBoxSend->TabIndex = 8;
			// 
			// tBoxReciv
			// 
			this->tBoxReciv->Location = System::Drawing::Point(20, 40);
			this->tBoxReciv->Multiline = true;
			this->tBoxReciv->Name = L"tBoxReciv";
			this->tBoxReciv->Size = System::Drawing::Size(217, 160);
			this->tBoxReciv->TabIndex = 9;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(331, 262);
			this->Controls->Add(this->tBoxReciv);
			this->Controls->Add(this->tBoxSend);
			this->Controls->Add(this->btnReciv);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnOpen);
			this->Controls->Add(this->cBoxBaudRate);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnSend);
			this->Controls->Add(this->cBoxCOMPORT);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		
		//поиск СОМ портов
	private: System::Void findPorts(System::Void) {

					 //array<String^>^ ports = SerialPort::GetPortNames();
					 //cBoxCOMPORT->Items->AddRange(ports);

					 array<Object^>^ ports = SerialPort::GetPortNames();
					 cBoxCOMPORT->Items->AddRange(ports); 
				 }

	private: System::Void btnSend_Click(System::Object^  sender, System::EventArgs^  e) {

				 if (serialPort1->IsOpen)
				 {
					String^ dataOut = tBoxSend->Text;
					 //serialPort1.Write(dataOut);
					 serialPort1->WriteLine(dataOut);
				 } 
				 else tBoxSend->Text = "Port is close!";
			 }

	private: System::Void btnOpen_Click(System::Object^  sender, System::EventArgs^  e) {

				 try
				 {
						 serialPort1->PortName = cBoxCOMPORT->Text;	
						 serialPort1->BaudRate = Int32::Parse(cBoxBaudRate->Text);

						 serialPort1->Open();
				 }
				 catch (UnauthorizedAccessException^) //(Exception err)
				 {
					 //tBoxReciv->Text = "ERROR";	
					 MessageBox::Show( "***ERROR***", "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error); //err.Message,
				 }
			 }
private: System::Void btnClose_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (serialPort1->IsOpen) 
			 {
				 serialPort1->Close();
			 } 
		 }
private: System::Void btnReciv_Click(System::Object^  sender, System::EventArgs^  e) {

			 if (serialPort1->IsOpen)
			 {
			 String^ dataIn = serialPort1->ReadLine();
			 tBoxReciv->Text = dataIn;
			 } 
			 else tBoxReciv->Text = "Port is close!";
		 }
};
}

