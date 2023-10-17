#include <iostream>
#include <fstream>
#include <vector>

struct Note{
    std::string title;
    std::string content;
};

class Notebook{
    private:
        std::vector<Note> notes;
    public:
        void addNote(){
            Note newNote;
            std::cout << "Enter note title: ";
            std::getline(std::cin, newNote.title);
            std::cout << "Enter note content: ";
            std::getline(std::cin, newNote.content);
            notes.push_back(newNote);
            std::cout << "Note added successfull\n";
        }
        void viewNote(){
            if(notes.empty()){
                std::cout << "No notes availables\n";
            }else{
                std::cout << "------ Your Notes ------\n";
                for(const auto &note : notes){
                    std::cout << "Title: " << note.title << '\n';
                    std::cout << "Content: " << note.content << '\n';
                }
            }
        }
        void saveToFile(){
            std::ofstream file("notes.txt");
            if(file.is_open()){
                for(const auto &note : notes){
                    file << "Title: " << note.title << '\n';
                    file << "Content: " << note.content << '\n';
                }
                file.close();
                std::cout << "Notes saved to file.\n";
            }else {
                std::cout << "Error saving to file.\n";
            }
        }
        void loadFromFile(){
            std::ifstream file("notes.txt");
            if(file.is_open()){
                Note currentNote;
                while(std::getline(file, currentNote.title)){
                    std::getline(file, currentNote.content);
                    notes.push_back(currentNote);
                }
                file.close();
                std::cout << "Notes loaded from file.\n";
            }else{
                std::cout << "No existing notes file found.\n";
            }
        }
};

int main(){
    Notebook notebook;
    notebook.loadFromFile();

    int choice;
    do{
        std::cout << "------ Personal Notebook ------\n";
        std::cout << "1. Add Note\n";
        std::cout << "2. View Notes\n";
        std::cout << "3. Save to File\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice){
        case 1:
            notebook.addNote();
            break;
        case 2:
            notebook.viewNote();
            break;
        case 3:
            notebook.saveToFile();
            break;
        case 4:
            std::cout << "Exiting!";
        default:
            break;
        }
    }while (choice != 4);
    
    return 0;
}

