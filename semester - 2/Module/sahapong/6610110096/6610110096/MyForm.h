#pragma once

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

namespace My6610110096 {
    using namespace System::Runtime::InteropServices;
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

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
            this->Text = L"S6610110096";
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
            delete image;
        }

    private:
        Bitmap^ bmp;
        cv::Mat* image = new cv::Mat();
        System::Windows::Forms::ToolStripContainer^ toolStripContainer1;
        System::Windows::Forms::MenuStrip^ menuStrip1;
        System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
        System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
        System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
        System::Diagnostics::EventLog^ eventLog1;
    private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
    private: System::Windows::Forms::PictureBox^ pictureBox1;
    private: System::Windows::Forms::ToolStripMenuItem^ imageToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ drawLineToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ drawCircleToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ convertHSVToolStripMenuItem;


    private:
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
            this->toolStripContainer1 = (gcnew System::Windows::Forms::ToolStripContainer());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
            this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->imageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->drawLineToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->drawCircleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->convertHSVToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->eventLog1 = (gcnew System::Diagnostics::EventLog());
            this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
            this->toolStripContainer1->ContentPanel->SuspendLayout();
            this->toolStripContainer1->TopToolStripPanel->SuspendLayout();
            this->toolStripContainer1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->menuStrip1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->eventLog1))->BeginInit();
            this->SuspendLayout();
            // 
            // toolStripContainer1
            // 
            // 
            // toolStripContainer1.ContentPanel
            // 
            this->toolStripContainer1->ContentPanel->Controls->Add(this->pictureBox1);
            this->toolStripContainer1->ContentPanel->Size = System::Drawing::Size(284, 237);
            this->toolStripContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->toolStripContainer1->Location = System::Drawing::Point(0, 0);
            this->toolStripContainer1->Name = L"toolStripContainer1";
            this->toolStripContainer1->Size = System::Drawing::Size(284, 261);
            this->toolStripContainer1->TabIndex = 0;
            this->toolStripContainer1->Text = L"toolStripContainer1";
            // 
            // toolStripContainer1.TopToolStripPanel
            // 
            this->toolStripContainer1->TopToolStripPanel->Controls->Add(this->menuStrip1);
            // 
            // pictureBox1
            // 
            this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->pictureBox1->Location = System::Drawing::Point(0, 0);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(284, 237);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox1->TabIndex = 0;
            this->pictureBox1->TabStop = false;
            // 
            // menuStrip1
            // 
            this->menuStrip1->Dock = System::Windows::Forms::DockStyle::None;
            this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
                this->fileToolStripMenuItem,
                    this->imageToolStripMenuItem
            });
            this->menuStrip1->Location = System::Drawing::Point(0, 0);
            this->menuStrip1->Name = L"menuStrip1";
            this->menuStrip1->Size = System::Drawing::Size(284, 24);
            this->menuStrip1->TabIndex = 0;
            this->menuStrip1->Text = L"menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
                this->openToolStripMenuItem,
                    this->exitToolStripMenuItem
            });
            this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
            this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
            this->fileToolStripMenuItem->Text = L"File";
            // 
            // openToolStripMenuItem
            // 
            this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
            this->openToolStripMenuItem->Size = System::Drawing::Size(103, 22);
            this->openToolStripMenuItem->Text = L"Open";
            this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
            // 
            // exitToolStripMenuItem
            // 
            this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
            this->exitToolStripMenuItem->Size = System::Drawing::Size(103, 22);
            this->exitToolStripMenuItem->Text = L"Exit";
            this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
            // 
            // imageToolStripMenuItem
            // 
            this->imageToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
                this->drawLineToolStripMenuItem,
                    this->drawCircleToolStripMenuItem, this->convertHSVToolStripMenuItem
            });
            this->imageToolStripMenuItem->Name = L"imageToolStripMenuItem";
            this->imageToolStripMenuItem->Size = System::Drawing::Size(52, 20);
            this->imageToolStripMenuItem->Text = L"Image";
            this->imageToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::imageToolStripMenuItem_Click);
            // 
            // drawLineToolStripMenuItem
            // 
            this->drawLineToolStripMenuItem->Name = L"drawLineToolStripMenuItem";
            this->drawLineToolStripMenuItem->Size = System::Drawing::Size(180, 22);
            this->drawLineToolStripMenuItem->Text = L"Draw Line";
            this->drawLineToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::drawLineToolStripMenuItem_Click);
            // 
            // drawCircleToolStripMenuItem
            // 
            this->drawCircleToolStripMenuItem->Name = L"drawCircleToolStripMenuItem";
            this->drawCircleToolStripMenuItem->Size = System::Drawing::Size(180, 22);
            this->drawCircleToolStripMenuItem->Text = L"Draw Circle";
            this->drawCircleToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::drawCircleToolStripMenuItem_Click);
            // 
            // convertHSVToolStripMenuItem
            // 
            this->convertHSVToolStripMenuItem->Name = L"convertHSVToolStripMenuItem";
            this->convertHSVToolStripMenuItem->Size = System::Drawing::Size(180, 22);
            this->convertHSVToolStripMenuItem->Text = L"Convert to HSV";
            this->convertHSVToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::convertHSVToolStripMenuItem_Click);
            // 
            // eventLog1
            // 
            this->eventLog1->SynchronizingObject = this;
            // 
            // openFileDialog1
            // 
            this->openFileDialog1->FileName = L"openFileDialog1";
            this->openFileDialog1->Filter = L"Image files|*.jpg;*.png";
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(284, 261);
            this->Controls->Add(this->toolStripContainer1);
            this->MainMenuStrip = this->menuStrip1;
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->toolStripContainer1->ContentPanel->ResumeLayout(false);
            this->toolStripContainer1->TopToolStripPanel->ResumeLayout(false);
            this->toolStripContainer1->TopToolStripPanel->PerformLayout();
            this->toolStripContainer1->ResumeLayout(false);
            this->toolStripContainer1->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->menuStrip1->ResumeLayout(false);
            this->menuStrip1->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->eventLog1))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion

    private:
        System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {}

        private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
            {
                Bitmap^ image = gcnew Bitmap(openFileDialog1->FileName);
                bmp = gcnew Bitmap(image->Size.Width, image->Size.Height, Imaging::PixelFormat::Format24bppRgb);
                bmp->SetResolution(image->HorizontalResolution, image->VerticalResolution);
                Graphics^ g = Graphics::FromImage(bmp);
                g->DrawImage(image, 0, 0);
                delete image;
                pictureBox1->Image = bmp;
            }
        }

               System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
                   Close();
               }

        private: System::Void imageToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
            // This method is currently empty, but you can add any functionality you need here.
        }
        private: System::Void drawLineToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

            // Lock Bitmap Bits
            Rectangle rect = Rectangle(0, 0, bmp->Width, bmp->Height);
            System::Drawing::Imaging::BitmapData^ bmpData =

                bmp->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, bmp->PixelFormat);

            // Using OpenCV: Create Image with data pointer
            cv::Mat image(bmp->Height, bmp->Width, CV_8UC3, bmpData->Scan0.ToPointer(), bmpData->Stride);

            // Set line thickness (example: 5 pixels)
            int lineThickness = 5;

            // Do OpenCV function with thickness
            line(image, cv::Point(0, 0), cv::Point(bmp->Width, bmp->Height), CV_RGB(0, 255, 0), lineThickness);

            // Unlock Bitmap Bits
            bmp->UnlockBits(bmpData);
            pictureBox1->Image = bmp; // Show result
        }

        private: System::Void drawCircleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
            // Lock Bitmap Bits
            Rectangle rect = Rectangle(0, 0, bmp->Width, bmp->Height);
            System::Drawing::Imaging::BitmapData^ bmpData =
                bmp->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, bmp->PixelFormat);

            // Using OpenCV: Create Image with data pointer
            cv::Mat image(bmp->Height, bmp->Width, CV_8UC3, bmpData->Scan0.ToPointer(), bmpData->Stride);

            // Set circle parameters
            cv::Point center(bmp->Width / 2, bmp->Height / 2);  // Center of the image
            int radius = 80;  // Circle radius
            cv::Scalar color(0, 0, 255);  // Circle color (green)
            int thickness = 5;  // Line thickness

            // Draw circle on the image
            cv::circle(image, center, radius, color, thickness);

            // Unlock Bitmap Bits
            bmp->UnlockBits(bmpData);
            pictureBox1->Image = bmp;  // Show result
        }

        private: System::Void convertHSVToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
            if (bmp == nullptr) {
                MessageBox::Show("No image loaded. Please load an image first.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            // Lock Bitmap Bits
            Rectangle rect = Rectangle(0, 0, bmp->Width, bmp->Height);
            System::Drawing::Imaging::BitmapData^ bmpData =
                bmp->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, bmp->PixelFormat);

            // Using OpenCV: Create Image with data pointer
            cv::Mat image(bmp->Height, bmp->Width, CV_8UC3, bmpData->Scan0.ToPointer(), bmpData->Stride);

            // Convert BGR to HSV
            cv::Mat hsvImage;
            cv::cvtColor(image, hsvImage, cv::COLOR_BGR2HSV);

            // Copy HSV image back to Bitmap
            std::memcpy(bmpData->Scan0.ToPointer(), hsvImage.data, bmp->Height * bmpData->Stride);

            // Unlock Bitmap Bits
            bmp->UnlockBits(bmpData);

            // Update PictureBox
            pictureBox1->Image = bmp;
        }



};
}