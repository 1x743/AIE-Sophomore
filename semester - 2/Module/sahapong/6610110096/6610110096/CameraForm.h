#pragma once
#include <opencv2/videoio.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
namespace My6610110096 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;


	/// <summary>
	/// Summary for CameraForm
	/// </summary>
	public ref class CameraForm : public System::Windows::Forms::Form
	{
	public:
		CameraForm(void)
		{
			InitializeComponent();
		}

	protected:
		~CameraForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::PictureBox^ pictureBox;
	private: System::Windows::Forms::Label^ captureWHLabel;


	private: System::Windows::Forms::Button^ startButton;

	protected:

	private:
		Bitmap^ bmp;
		bool isStart = false;
	private: System::Windows::Forms::Label^ captureFPSLabel;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;

		   /// <summary>
		/// Required designer variable.
		/// </summary>
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			   this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->captureFPSLabel = (gcnew System::Windows::Forms::Label());
			   this->startButton = (gcnew System::Windows::Forms::Button());
			   this->captureWHLabel = (gcnew System::Windows::Forms::Label());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			   this->splitContainer1->Panel1->SuspendLayout();
			   this->splitContainer1->Panel2->SuspendLayout();
			   this->splitContainer1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // splitContainer1
			   // 
			   this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->splitContainer1->Location = System::Drawing::Point(0, 0);
			   this->splitContainer1->Name = L"splitContainer1";
			   // 
			   // splitContainer1.Panel1
			   // 
			   this->splitContainer1->Panel1->Controls->Add(this->pictureBox);
			   // 
			   // splitContainer1.Panel2
			   // 
			   this->splitContainer1->Panel2->Controls->Add(this->button2);
			   this->splitContainer1->Panel2->Controls->Add(this->button1);
			   this->splitContainer1->Panel2->Controls->Add(this->label2);
			   this->splitContainer1->Panel2->Controls->Add(this->label1);
			   this->splitContainer1->Panel2->Controls->Add(this->captureFPSLabel);
			   this->splitContainer1->Panel2->Controls->Add(this->startButton);
			   this->splitContainer1->Panel2->Controls->Add(this->captureWHLabel);
			   this->splitContainer1->Size = System::Drawing::Size(683, 498);
			   this->splitContainer1->SplitterDistance = 361;
			   this->splitContainer1->TabIndex = 0;
			   // 
			   // pictureBox
			   // 
			   this->pictureBox->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pictureBox->Location = System::Drawing::Point(0, 0);
			   this->pictureBox->Name = L"pictureBox";
			   this->pictureBox->Size = System::Drawing::Size(361, 498);
			   this->pictureBox->TabIndex = 0;
			   this->pictureBox->TabStop = false;
			   // 
			   // label2
			   // 
			   this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->label2->Font = (gcnew System::Drawing::Font(L"JetBrainsMonoNL NF ExtraBold", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label2->Location = System::Drawing::Point(50, 34);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(213, 34);
			   this->label2->TabIndex = 0;
			   this->label2->Text = L"Work 4: Camera Preview";
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"JetBrainsMonoNL NFM ExtraBold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->Location = System::Drawing::Point(10, 82);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(298, 25);
			   this->label1->TabIndex = 3;
			   this->label1->Text = L"Nuttasit Tinmas 6610110096";
			   // 
			   // captureFPSLabel
			   // 
			   this->captureFPSLabel->Location = System::Drawing::Point(10, 434);
			   this->captureFPSLabel->Name = L"captureFPSLabel";
			   this->captureFPSLabel->Size = System::Drawing::Size(100, 23);
			   this->captureFPSLabel->TabIndex = 0;
			   this->captureFPSLabel->Text = L"FPS: ";
			   // 
			   // startButton
			   // 
			   this->startButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			   this->startButton->Location = System::Drawing::Point(231, 463);
			   this->startButton->Name = L"startButton";
			   this->startButton->Size = System::Drawing::Size(75, 23);
			   this->startButton->TabIndex = 2;
			   this->startButton->Text = L"Start";
			   this->startButton->UseVisualStyleBackColor = true;
			   this->startButton->Click += gcnew System::EventHandler(this, &CameraForm::startButton_Click);
			   // 
			   // captureWHLabel
			   // 
			   this->captureWHLabel->AutoSize = true;
			   this->captureWHLabel->Location = System::Drawing::Point(10, 409);
			   this->captureWHLabel->Name = L"captureWHLabel";
			   this->captureWHLabel->Size = System::Drawing::Size(89, 13);
			   this->captureWHLabel->TabIndex = 1;
			   this->captureWHLabel->Text = L"Image Size: WxH";
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(56, 156);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(75, 23);
			   this->button1->TabIndex = 4;
			   this->button1->Text = L"Show HSV";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &CameraForm::button1_Click);
			   // 
			   // button2
			   // 
			   this->button2->Location = System::Drawing::Point(188, 156);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(75, 23);
			   this->button2->TabIndex = 5;
			   this->button2->Text = L"B/W";
			   this->button2->UseVisualStyleBackColor = true;
			   this->button2->Click += gcnew System::EventHandler(this, &CameraForm::button2_Click);
			   // 
			   // CameraForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(683, 498);
			   this->Controls->Add(this->splitContainer1);
			   this->Name = L"CameraForm";
			   this->Text = L"CameraForm";
			   this->splitContainer1->Panel1->ResumeLayout(false);
			   this->splitContainer1->Panel2->ResumeLayout(false);
			   this->splitContainer1->Panel2->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			   this->splitContainer1->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void startButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (isStart) {

			isStart = false;
			startButton->Text = "Start";
			return;

		}
		VideoCapture capture(0);// 0, cv::CAP_MSMF);
		while (!capture.isOpened());
		int capWidth = (int)capture.get(CAP_PROP_FRAME_WIDTH);
		int capHeight = (int)capture.get(CAP_PROP_FRAME_HEIGHT);
		int capFPS = (int)capture.get(CAP_PROP_FPS);
		captureWHLabel->Text = System::String::Format("Image Size: {0:D}x{1:D}", capWidth, capHeight);
		captureFPSLabel->Text = System::String::Format("FPS: {0:D}", capFPS);
		isStart = true;
		bmp = gcnew Bitmap(capWidth, capHeight, PixelFormat::Format24bppRgb);
		Rectangle rect = Rectangle(0, 0, bmp->Width, bmp->Height);
		startButton->Text = "Stop";
		while (isStart) {

			BitmapData^ bmpData = bmp->LockBits(rect, ImageLockMode::ReadWrite, bmp->PixelFormat);

			// Using OpenCV: Create Image with data pointer
			Mat image(bmp->Height, bmp->Width, CV_8UC3, bmpData->Scan0.ToPointer(), bmpData->Stride);


			capture.read(image);
			// Unlock Bitmap Bits
			bmp->UnlockBits(bmpData);
			pictureBox->Image = bmp;
			Application::DoEvents();

		}
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	// Handle HSV conversion toggle
	if (!isStart) return; // If the camera is not running, do nothing
	VideoCapture capture(0);
	if (!capture.isOpened()) return;

	isStart = true;
	int capWidth = (int)capture.get(CAP_PROP_FRAME_WIDTH);
	int capHeight = (int)capture.get(CAP_PROP_FRAME_HEIGHT);
	bmp = gcnew Bitmap(capWidth, capHeight, PixelFormat::Format24bppRgb);
	Rectangle rect = Rectangle(0, 0, bmp->Width, bmp->Height);

	while (isStart) {
		BitmapData^ bmpData = bmp->LockBits(rect, ImageLockMode::ReadWrite, bmp->PixelFormat);

		// Using OpenCV: Create Image with data pointer
		Mat image(bmp->Height, bmp->Width, CV_8UC3, bmpData->Scan0.ToPointer(), bmpData->Stride);
		Mat hsvImage;

		capture.read(image);
		if (image.empty()) break;

		// Convert the captured image to HSV
		cvtColor(image, hsvImage, COLOR_BGR2HSV);

		// Copy the HSV image data back to the bitmap
		std::memcpy(image.data, hsvImage.data, hsvImage.total() * hsvImage.elemSize());

		// Unlock Bitmap Bits
		bmp->UnlockBits(bmpData);
		pictureBox->Image = bmp;
		Application::DoEvents();
	}
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	// Handle Black & White conversion toggle
	if (!isStart) return; // If the camera is not running, do nothing
	VideoCapture capture(0);
	if (!capture.isOpened()) return;

	isStart = true;
	int capWidth = (int)capture.get(CAP_PROP_FRAME_WIDTH);
	int capHeight = (int)capture.get(CAP_PROP_FRAME_HEIGHT);
	bmp = gcnew Bitmap(capWidth, capHeight, PixelFormat::Format24bppRgb);
	Rectangle rect = Rectangle(0, 0, bmp->Width, bmp->Height);

	while (isStart) {
		BitmapData^ bmpData = bmp->LockBits(rect, ImageLockMode::ReadWrite, bmp->PixelFormat);

		// Using OpenCV: Create Image with data pointer
		Mat image(bmp->Height, bmp->Width, CV_8UC3, bmpData->Scan0.ToPointer(), bmpData->Stride);
		Mat grayImage;

		capture.read(image);
		if (image.empty()) break;

		// Convert the captured image to grayscale
		cvtColor(image, grayImage, COLOR_BGR2GRAY);

		// Convert single channel grayscale image to 3 channels for displaying in PictureBox
		cvtColor(grayImage, image, COLOR_GRAY2BGR);

		// Unlock Bitmap Bits
		bmp->UnlockBits(bmpData);
		pictureBox->Image = bmp;
		Application::DoEvents();
	}
}

};
}
