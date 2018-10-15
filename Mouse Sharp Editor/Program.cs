using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Mouse_Sharp_Editor
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main(string[] args)
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            try
            {
                if (args != null || args.Length != 0)
                {
                    // run with a file.
                    Form1 form1 = new Form1();
                    form1.fileName = args[0];
                    form1.Show();
                    form1.textEditorControl1.Text = File.ReadAllText(form1.fileName);
                    form1.textEditorControl1.Refresh();
                    Application.Run(form1);
                }
                else
                {
                    // run without a file.
                    Application.Run(new Form1());
                }
            } catch // some reason we did not get any arguements and got an errror ..
            {
                Application.Run(new Form1());
            }
           
        }
    }
}
