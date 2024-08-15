# Sea++ Application

## Overview
Sea++ is a graphical user interface (GUI) application designed with Qt that features a dialog window with interactive buttons and a dynamic layout. This application is structured using Qt’s framework, providing a visually appealing and user-friendly interface.

## Features
- **Dialog Window**: A central `QDialog` window with a customized appearance and layout.
- **Styled Buttons**: Multiple `QPushButton` widgets with consistent styling and custom images.
- **Dynamic Label**: A prominent `QLabel` for displaying language or title information.
- **Background Widget**: A dedicated background widget with a similarly styled label.

## UI Design
The UI is designed with the following elements:

- **Dialog Properties**
  - **Size**: 800x600 pixels
  - **Title**: "Sea++"
  - **Background**: Blue with transparency

- **Buttons**
  - **Font**: 10pt, bold, weight 75
  - **Text Color**: White
  - **Background Color**: Blanchedalmond
  - **Border Image**: `gif/crate.jpg`
  - **Padding**: 3px
  - **Special Button**: "New Treasure" with DejaVu Sans 17pt font, light cyan text, no background, and no border.

- **Label**
  - **ID**: `langName`
  - **Position**: (130, 25)
  - **Size**: 540x50 pixels
  - **Font**: 18pt, bold, weight 75
  - **Text Color**: Blue
  - **Background Color**: Blanchedalmond
  - **Style**: Box frame, sunken shadow

- **Background Widget**
  - **ID**: `backgroundWidget`
  - **Position**: (0, 60)
  - **Size**: 800x600 pixels
  - **Contains**: A `QLabel` with similar properties to the `langName` label

## Getting Started

### Prerequisites 
- Qt framework (version X.X or higher)
- C++ compiler compatible with Qt

### Installation
1. **Clone the Repository**
   ```bash
   git clone https://github.com/TravisAdamson/atlas-HackSprintCPP.git
   ```

2. **Navigate to the Project Directory**
   ```bash
   cd sea++
   ```

3. **Build the Application**
   ```bash
   qmake
    make
    ```

4. **Running the Application**
   Execute the built binary from the project directory:
   ```bash
   ./sea++
   ```

## Contributing
To contribute to the Sea++ project, please follow these steps:

1. **Fork the Repository**

2. **Create a New Branch**
   ```bash
   git checkout -b feature/new-feature
   ```

3. **Commit Your Changes**
   ```bash
   git commit -am (Add new feature)
   ```

4. **Push to the Branch**
   ```bash
   git push origin feature/new-feature
   ```

## License
This project is licensed under the MIT License. See the LICENSE file for details.

## Contact the Authors
For any questions or support, please contact us:
- Matthew Ernst - Matthew.Ernst@atlasschool.com
- Travis Adamson - Travis.Adamson@atlasschool.com
- Nolan Heald - Nolan.Heald@atlasschool.com

## Additional Install Instructions

### Qt Installation Instructions

#### Windows
1. **Download the Qt Installer**
   Go to the [Qt official website](https://www.qt.io/download-dev#eval-form-modal) and download the Qt Online Installer.

2. **Run the Installer**
   Execute the downloaded installer file.

3. **Login or Create a Qt Account**
   You will need a Qt account to proceed with the installation. Create one if you don’t have one.

4. **Choose Installation Options**
   Select components including the Qt version and the Qt Creator IDE.

5. **Complete the Installation**
   Follow the prompts to finish the installation process.

6. **Set Environment Variables** (if necessary)
   You may need to set the PATH environment variable to include the Qt bin directory.

#### macOS
1. **Download the Qt Installer**
   Visit the Qt official website and download the macOS installer.

2. **Run the Installer**
   Open the downloaded .dmg file and run the installer package.

3. **Login or Create a Qt Account**
   Log in or create a Qt account to continue.

4. **Select Installation Options**
   Choose components to ensure Qt version and Qt Creator IDE are included.

5. **Complete the Installation**
   Follow the prompts to complete the installation.

6. **Set Environment Variables** (if necessary)
   Set QT_QPA_PLATFORM_PLUGIN_PATH if you encounter issues.

#### Linux
1. **Download the Qt Installer**
   Download the Linux installer from the Qt website.

2. **Make the Installer Executable**
   ```bash 
   chmod+x qt-unified-linux-x.x.x-online.run
   ```

3. **Run the Installer**
   ```bash 
   ./qt-unified-linux-x.x.x-online.run
   ```
4. **Login or Create a Qt Account**
   Log in or create a Qt account as prompted by the installer.

5. **Choose Installation Options**
   Select the necessary components to install.

6. **Complete the Installation**
   Follow the prompts to finish the installation.

7. **Set Environment Variables** (if necessary)
   Add Qt’s bin directory to your PATH:
   ```bash
   export PATH=/opt/qt/bin:$PATH
   ```

8. **Verify the Installation**
   After installing Qt, verify it by running:
   ```bash
   qmake --version
   ```

### Installing qmake
#### Windows
1. **Install Qt** (qmake is included)
2. **Verify Installation**
   ```bash
   qmake --version
   ```

3. **Set Environment Variables** (if necessary)
   ```bash
   set PATH=C:\Qt\5.15.2\msvc2019_64\bin;%PATH%
   ```

#### macOS
1. **Install Qt** using the Qt Installer.
2. **Verify Installation**
   ```bash
   qmake --version
   ```

3. **Set Environment Variables** (if necessary)
   ```bash
   export PATH=/usr/local/Qt-5.15.2/bin:$PATH
   ```

#### Linux
1. **Install Qt Development Packages**
   ```bash
   sudo apt-get update
   sudo apt-get install qt5-qmake qtbase5-dev
   ```

2. **Verify Installation**
   ```bash
   qmake --version
   ```

3. **Set Environment Variables** (if necessary)
   If `qmake` is not recognized, ensure it's in your PATH. This is typically handled by the package manager.