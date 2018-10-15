using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using ICSharpCode.TextEditor;
using ICSharpCode.TextEditor.Document;
using System.IO;
using System.Diagnostics;
using System.Threading;

namespace Mouse_Sharp_Editor
{
    public partial class Form1 : Form
    {
        public string fileName = "";

        public Form1()
        {
            InitializeComponent();
        }

        private void textEditorControl1_Load(object sender, EventArgs e)
        {
                TextAreaControl textAreaControl =  textEditorControl1.ActiveTextAreaControl;

                // Make sure something's selected
                if (textAreaControl.SelectionManager.HasSomethingSelected)
                {
                    // Get the (first) selection
                    ISelection currentSelection = textAreaControl.SelectionManager.SelectionCollection[0];

                    // get the selected text.
                    string selectedText = currentSelection.SelectedText;
                }
        }

        public void UpdateWorkSpace()
        {
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Color color = Color.FromArgb(220, 220, 220);
            Color backgroundColor = Color.FromArgb(60, 63, 65);
            HighlightColor highlightColor = new HighlightColor(color, backgroundColor, false, false);

            // Update the text editor's fore and background colour.
            DefaultHighlightingStrategy highlightingStrategy = textEditorControl1.Document.HighlightingStrategy as DefaultHighlightingStrategy;
            highlightingStrategy.SetColorFor("Default", highlightColor);
            highlightingStrategy.SetColorFor("LineNumbers", highlightColor);
            highlightingStrategy.SetColorFor("FoldLine", highlightColor);


            string dirc = Application.StartupPath;
            FileSyntaxModeProvider fsmp;
            if (Directory.Exists(dirc))
            {

                fsmp = new FileSyntaxModeProvider(dirc);
                HighlightingManager.Manager.AddSyntaxModeFileProvider(fsmp);
                textEditorControl1.SetHighlighting("MouseSharp");
            }

            Refresh();

            if (fileName != "")
            {

            }
        }


        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            textEditorControl1.Text = ":Main " + Environment.NewLine +
                "Echo \"Hello, World\";" + Environment.NewLine +
                "Pause;";
            textEditorControl1.Refresh();
            fileName = "";
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        public void ShowErrorMessage(string error, Exception exception)
        {
            DialogResult d = MessageBox.Show(this.Owner, error + ", would you like to see the error message?", "Error - Mouse Script Editor", MessageBoxButtons.YesNo, MessageBoxIcon.Error);
            if (d == DialogResult.Yes)
            {
                MessageBox.Show(this.Owner, exception.Message, "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        void SaveAs()
        {
            try
            {
                SaveFileDialog saveFileDialog1 = new SaveFileDialog();

                saveFileDialog1.Title = "Save Mouse Script Files";

                saveFileDialog1.CheckPathExists = true;

                saveFileDialog1.DefaultExt = "mscript";

                saveFileDialog1.Filter = "Mouse Script files (*.mscript)|*.mscript|All files (*.*)|*.*";

                saveFileDialog1.FilterIndex = 1;

                saveFileDialog1.RestoreDirectory = true;



                if (saveFileDialog1.ShowDialog() == DialogResult.OK)

                {
                    File.WriteAllText(saveFileDialog1.FileName, textEditorControl1.Text);
                    fileName = saveFileDialog1.FileName;
                }

            } catch (Exception ez)
            {
                ShowErrorMessage("The editor was unable to save the file", ez);
            }
        }

        private void openFolderToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            try
            {
                Process.Start("explorer.exe",  Path.GetDirectoryName( fileName));
            } catch (Exception ez)
            {
                ShowErrorMessage("Something went wrong when we tried to open the file", ez);
            }
        }


        private void openToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            try
            {
                OpenFileDialog openFileDialog1 = new OpenFileDialog();

                openFileDialog1.Title = "Open a Mouse Script File.";



                openFileDialog1.CheckFileExists = true;

                openFileDialog1.CheckPathExists = true;



                openFileDialog1.DefaultExt = "mscript";

                openFileDialog1.Filter = "Mouse Script files (*.mscript)|*.mscript|All files (*.*)|*.*";

                openFileDialog1.FilterIndex = 1;

                openFileDialog1.RestoreDirectory = true;



                openFileDialog1.ReadOnlyChecked = true;

                openFileDialog1.ShowReadOnly = true;

                if (openFileDialog1.ShowDialog() == DialogResult.OK)
                {
                    textEditorControl1.Text = File.ReadAllText(openFileDialog1.FileName);
                    fileName = openFileDialog1.FileName;
                    textEditorControl1.Refresh();
                }
            }
            catch (Exception ez)
            {
                ShowErrorMessage("The editor was unable to open the file", ez);
            }
        }

        private void saveToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            try
            {
                if (fileName != string.Empty)
                {
                    File.WriteAllText(fileName, textEditorControl1.Text);
                }
                else
                {
                    SaveAs();
                }
            }
            catch
            {
                SaveAs();
            }
        }

        void ChangeFont()
        {
            try
            {
                FontDialog fontDialog1 = new FontDialog();

                DialogResult result = fontDialog1.ShowDialog();
                if (result == DialogResult.OK)
                {
                    Font font = fontDialog1.Font;
                    textEditorControl1.Font = font;
                }
            }
            catch (Exception ez)
            {
                ShowErrorMessage("The choosen font is not supported", ez);
            }
        }

        private void saveAsToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            SaveAs();
        }

        private void exitToolStripMenuItem_Click_1(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void undoToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            textEditorControl1.Undo();
        }

        private void redoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            textEditorControl1.Redo();
        }

        private void cutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            textEditorControl1.ActiveTextAreaControl.TextArea.ClipboardHandler.Cut(sender, e);
        }

        private void copyToolStripMenuItem_Click(object sender, EventArgs e)
        {
            textEditorControl1.ActiveTextAreaControl.TextArea.ClipboardHandler.Copy(sender, e);
        }

        private void pasteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            textEditorControl1.ActiveTextAreaControl.TextArea.ClipboardHandler.Paste(sender, e);
        }

        private void deleteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            textEditorControl1.ActiveTextAreaControl.TextArea.ClipboardHandler.Delete(sender, e);
        }

        private void findToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            
        }

        private void replaceToolStripMenuItem1_Click(object sender, EventArgs e)
        {

        }

        private void sellectAllToolStripMenuItem_Click(object sender, EventArgs e)
        {
            textEditorControl1.ActiveTextAreaControl.TextArea.ClipboardHandler.SelectAll(sender, e);
        }

        private void contextMenuStrip1_Opening(object sender, CancelEventArgs e)
        {

        }

        private void darkStatusStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        // RUN FILE
        private void toolStripButton2_Click(object sender, EventArgs e)
        {
            try
            {
                saveToolStripMenuItem1_Click(sender, e);
                if (fileName != "")
                {
                    Process.Start(fileName);
                } 
                else
                {
                    MessageBox.Show("You have not selected a file!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            } catch (Exception ez)
            {
                ShowErrorMessage("A error has occured while trying to run the file \"" + fileName + "\"", ez);
            }
        }

        private void darkListView1_Click(object sender, EventArgs e)
        {
            
        }

        private void EncryptButton_Click(object sender, EventArgs e)
        {
            try
            {
                saveToolStripMenuItem1_Click(sender, e);
                if (fileName != "")
                {
                    Process.Start("MouseScript.exe", "-e " + fileName);
                }
                else
                {
                    MessageBox.Show("You have not selected a file!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            catch (Exception ez)
            {
                ShowErrorMessage("A error has occured while trying to run the file \"" + fileName + "\"", ez);
            }
        }

    }
}
