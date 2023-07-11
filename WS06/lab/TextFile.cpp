/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 6 
// Version 1.0
// Description
// tester program
//
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
//
// Revision History
// -----------------------------------------------------------
// Name              Date           Reason
// Leonardo Caceres  2023/July/7    Preliminary release     
/////////////////////////////////////////////////////////////////
***********************************************************************/
//#include "TextFile.h"
//using namespace std;
//namespace sdds {
//   Line::operator const char* () const {
//       return (const char*)m_value;
//   }
//   Line& Line::operator=(const char* lineValue) {
//       delete[] m_value;
//       m_value = new char[strLen(lineValue) + 1];
//       strCpy(m_value, lineValue);
//       return *this;
//   }
//   Line::~Line() {
//       delete[] m_value;
//   }
//
//   void TextFile::setFilename(const char *fname, bool isCopy)
//   {
//      clearFilename();
//
//      if (!isCopy && fname){
//         m_filename = new char[strLen(fname) + 1];
//         strCpy(m_filename, fname);
//      }
//      else{
//         m_filename = new char[strLen(fname) + 3];
//         strCpy(m_filename, "C_");
//         strCpy(m_filename + 2, fname);
//      }
//   } 
//   void TextFile::setNoOfLines()
//   {
//      string str;
//      ifstream is;
//      is.open(m_filename);
//
//      if (is) {
//          m_noOfLines = 0;
//
//          while(getline(is, str))
//            ++m_noOfLines;
//      }
//
//      is.close();
//   }
//   void TextFile::loadText()
//   {
//       ifstream is;
//       string str;
//       size_t i;
//
//       if(*this && m_noOfLines > 0)
//       {
//           setNoOfLines();
//           clearTextLines();
//           m_textLines = new Line[m_noOfLines];
//       
//           is.open(m_filename);
//
//           i = 0;
//           while (getline(is, str) && i < m_noOfLines){
//               m_textLines[i] = str.c_str();
//               ++i;
//           }
//
//           m_noOfLines = i;
//           is.close();
//       }
//   }
//   void TextFile::saveAs(const char *fileName) const
//   {
//      ofstream os(fileName);
//      for (size_t i = 0; i < m_noOfLines; i++)
//         os << m_textLines[i] << '\n';
//      os.close();
//   }
//   void TextFile::setEmpty()
//   {
//      clearFilename();
//      clearTextLines();
//      m_noOfLines = 0;
//      m_pageSize = 0;
//   }
//   void TextFile::clearFilename()
//   {
//      //if(m_filename){
//         delete[] m_filename;
//         m_filename = nullptr; 
//        //}
//   }
//   void TextFile::clearTextLines()
//   {
//      //if(m_textLines){
//         delete[] m_textLines;
//         m_textLines = nullptr;
//      //}
//   }
//   void TextFile::copyTextFile(const TextFile& t)
//   {
//       setFilename(t.name(), true);
//       setNoOfLines();
//       saveAs(m_filename);
//       loadText();
//   }
//
//   TextFile::TextFile(unsigned pageSize): m_pageSize(pageSize) {}
//   TextFile::TextFile(const char *filename, unsigned pageSize): m_pageSize(pageSize) 
//   {
//      if(filename){
//         setFilename(filename);
//         setNoOfLines();
//         loadText();
//      }
//   }
//   TextFile::TextFile(const TextFile& t): m_pageSize(t.m_pageSize)
//   {
//       if (*this && t) 
//           copyTextFile(t);
//   }
//   TextFile &TextFile::operator=(const TextFile& t)
//   {
//       if (t) {
//         setEmpty();
//         copyTextFile(t);
//      }
//      return *this;
//   }
//   TextFile::~TextFile()
//   {
//      setEmpty();
//   }
//
//   std::ostream &TextFile::view(std::ostream &ostr) const
//   {
//       if (*this && m_textLines) {
//         ostr << m_filename << '\n';
//         for (size_t i = 0; i < strLen(name()); i++)
//            ostr << '=';
//         ostr << '\n';
//
//         size_t j = 1;
//         for (size_t i = 0; i < m_noOfLines; i++){
//            ostr << m_textLines[i];
//            if(j == m_pageSize ){
//               ostr << endl << "Hit ENTER to continue...";
//                   while (getchar() != '\n');
//               j = 0;
//            }
//            else ostr << endl;
//            j++;
//         }
//      }   
//      
//      return ostr;
//   }
//   std::istream &TextFile::getFile(std::istream &istr)
//   {
//      string fname;
//      istr >> fname;
//
//      if (!fname.empty())
//      {
//          setFilename(fname.c_str());
//          loadText();
//      }
//      return istr;
//   }
//   TextFile::operator bool() const
//   {
//      return m_filename && m_filename[0] != '\n';
//   }
//   unsigned TextFile::lines() const
//   {
//      return m_noOfLines;
//   }
//   const char *TextFile::name() const
//   {
//      return m_filename;
//   }
//   const char *TextFile::operator[](unsigned index) const
//   {
//      return (*this && m_textLines && index < m_noOfLines)
//         ? m_textLines[index % m_noOfLines].m_value 
//         : nullptr;
//   }
//   std::ostream &operator<<(std::ostream &ostr, const TextFile &text)
//   {
//      return text.view(ostr);
//   }
//   std::istream &operator>>(std::istream &istr, TextFile &text)
//   {
//      return text.getFile(istr);
//   }
//}
//////////////////////////////////////////



#include "TextFile.h"
using namespace std;
namespace sdds {
    Line::operator const char* () const {
        return (const char*)m_value;
    }
    Line& Line::operator=(const char* lineContent) {
        delete[] m_value;
        m_value = new char[strLen(lineContent) + 1];
        strCpy(m_value, lineContent);
        return *this;
    }
    Line::~Line() {
        delete[] m_value;
    }

    TextFile::TextFile(unsigned pageSize): m_pageSize(pageSize) {}

    TextFile::TextFile(const char* filename, unsigned pageSize) : m_pageSize(pageSize) {
        setFilename(filename);
        setNoOfLines();
        loadText();
    }

    TextFile::TextFile(const TextFile& other) : m_pageSize(other.m_pageSize) {
        if (other.m_filename != nullptr) {
            setFilename(other.m_filename, true);
            saveAs(m_filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile& TextFile::operator=(const TextFile& other) {
        if (this != &other) {
            delete[] m_textLines;
            m_textLines = nullptr;
            delete[] m_filename;
            m_filename = nullptr;
            m_pageSize = other.m_pageSize;
            if (other.m_filename != nullptr) {
                setFilename(other.m_filename, true);
                saveAs(m_filename);
                setNoOfLines();
                loadText();
            }
        }
        return *this;
    }

    TextFile::~TextFile() {
        delete[] m_textLines;
        m_textLines = nullptr;
        delete[] m_filename;
        m_filename = nullptr;
    }

    std::ostream& TextFile::view(std::ostream& ostr) const {
        if (m_filename != nullptr) {
            ostr << m_filename << endl;
            for (unsigned i = 0; i < m_noOfLines; i++) {
                ostr << (i + 1) << ": " << m_textLines[i] << endl;
                if ((i + 1) % m_pageSize == 0) {
                    ostr << "Hit ENTER to continue...";
                    cin.ignore();
                }
            }
        }
        return ostr;
    }

    std::istream& TextFile::getFile(std::istream& istr) {
        string filename;
        istr >> filename;
        setFilename(filename.c_str());
        setNoOfLines();
        loadText();
        return istr;
    }

    unsigned TextFile::lines() const {
        return m_noOfLines;
    }

    const char* TextFile::name() const {
        return m_filename;
    }

    const char* TextFile::operator[](unsigned index) const {
        if (m_filename == nullptr || m_noOfLines == 0)
            return nullptr;
        return m_textLines[index % m_noOfLines];
    }

    TextFile::operator bool() const {
        return (m_filename != nullptr);
    }

    void TextFile::setFilename(const char* fname, bool isCopy) {
        delete[] m_filename;

        if (fname) {
            m_filename = new char[strLen(fname) + (isCopy ? 3 : 1)];

            if (isCopy) {
                strCpy(m_filename, "C_");
                strCat(m_filename, fname);
            }
            else 
                strCpy(m_filename, fname);
        }
    }

    void TextFile::setNoOfLines() {
        ifstream file(m_filename);
        char ch;
        m_noOfLines = 0;
        while (file.get(ch)) { // get isn't returning any value
            if (ch == '\n')
                m_noOfLines++;
        }
        m_noOfLines++;
        if (m_noOfLines == 0) {
            delete[] m_filename;
            m_filename = nullptr;
        }
        //file.close();
    }

    void TextFile::loadText() {
        if (m_filename != nullptr) {
            delete[] m_textLines;
            m_textLines = new Line[m_noOfLines];
            ifstream file(m_filename);
            for (unsigned i = 0; i < m_noOfLines; i++) {
                string line;
                getline(file, line);
                m_textLines[i] = line.c_str();
            }
            //file.close();
        }
    }

    void TextFile::saveAs(const char* fileName) const {
        ofstream file(fileName);
        for (unsigned i = 0; i < m_noOfLines; i++)
            file << m_textLines[i] << '\n';
    }

    void TextFile::setEmpty() {
        delete[] m_textLines;
        m_textLines = nullptr;
        delete[] m_filename;
        m_filename = nullptr;
        m_noOfLines = 0;
    }

    ostream& operator<<(ostream& ostr, const TextFile& text) {
        return text.view(ostr);
    }

    istream& operator>>(istream& istr, TextFile& text) {
        return text.getFile(istr);
    }
}