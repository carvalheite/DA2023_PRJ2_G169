//
// Created by miguel on 17-05-2024.
//

#include "Menu.h"

Menu::Menu() : g(), data(&g) { // Properly initialize g and data
}

void Menu::run(){
    mainMenu();
}

void Menu::mainMenu(){
    char op;
    cout << "__________________________________________\n";
    cout << "|                MainMenu                |\n";
    cout << "|        Choose one of the options       |\n";
    cout << "|________________________________________|\n";
    cout << "|      1. Toy-Graphs                     |\n";
    cout << "|      2. Real-world Graphs              |\n";
    cout << "|      3. Extra-Fully-Connected Graphs   |\n";
    cout << "|      \033[31mq. QUIT \033[0m                          |\n";
    cout << "|________________________________________|\n";
    cout << "Your option:";
    cin >> op;
    switch(op)
    {
        case '1':
            ToyGraphsMenu();
            break;
        case '2':
            RealworldGraphsMenu();
            break;
        case '3':
            ExtraFullyConnectedGraphsMenu();
            break;
        case 'q':
            cout << "End" << endl;
            break;
        default:
            cout << "Invalid Option..." << endl;
            mainMenu();
            break;
    }
}

void Menu::ToyGraphsMenu(){
    char op;
    cout << "__________________________________________\n";
    cout << "|                Toy-Graphs              |\n";
    cout << "|        Choose one of the options       |\n";
    cout << "|________________________________________|\n";
    cout << "|      1. Shipping                       |\n";
    cout << "|      2. Stadiums                       |\n";
    cout << "|      3. Tourism                        |\n";
    cout << "|      \033[31mq. Go back \033[0m                       |\n";
    cout << "|________________________________________|\n";
    cout << "Your option:";
    cin >> op;
    switch(op)
    {
        case '1':
            g.clear();
            data.loadToyGraph(1);
            OperationsMenu(1);
            break;
        case '2':
            g.clear();
            data.loadToyGraph(2);
            OperationsMenu(1);
            break;
        case '3':
            g.clear();
            data.loadToyGraph(3);
            OperationsMenu(1);
            break;
        case 'q':
            mainMenu();
            break;
        default:
            cout << "Invalid Option..." << endl;
            ToyGraphsMenu();
            break;
    }
}
void Menu::RealworldGraphsMenu(){
    char op;
    cout << "__________________________________________\n";
    cout << "|            Real-world Graphs           |\n";
    cout << "|        Choose one of the options       |\n";
    cout << "|________________________________________|\n";
    cout << "|      1. Graph 1                        |\n";
    cout << "|      2. Graph 2                        |\n";
    cout << "|      3. Graph 3                        |\n";
    cout << "|      \033[31mq. Go back \033[0m                       |\n";
    cout << "|________________________________________|\n";
    cout << "Your option:";
    cin >> op;
    switch(op)
    {
        case '1':
            data.loadRealGraph(1);
            OperationsMenu(2);
            break;
        case '2':
            data.loadRealGraph(2);
            OperationsMenu(2);
            break;
        case '3':
            data.loadRealGraph(3);
            OperationsMenu(2);
            break;
        case 'q':
            mainMenu();
            break;
        default:
            cout << "Invalid Option..." << endl;
            RealworldGraphsMenu();
            break;
    }
}

void Menu::ExtraFullyConnectedGraphsMenu(){
    char op;
    cout << "__________________________________________\n";
    cout << "|       Extra Fully Connected Graphs     |\n";
    cout << "|        Choose one of the options       |\n";
    cout << "|________________________________________|\n";
    cout << "|      1. Edges 25                       |\n";
    cout << "|      2. Edges 50                       |\n";
    cout << "|      3. Edges 75                       |\n";
    cout << "|      4. Edges 100                      |\n";
    cout << "|      5. Edges 200                      |\n";
    cout << "|      6. Edges 300                      |\n";
    cout << "|      7. Edges 400                      |\n";
    cout << "|      8. Edges 500                      |\n";
    cout << "|      9. Edges 600                      |\n";
    cout << "|      10. Edges 700                     |\n";
    cout << "|      11. Edges 800                     |\n";
    cout << "|      12. Edges 900                     |\n";
    cout << "|      \033[31mq. Go back \033[0m                       |\n";
    cout << "|________________________________________|\n";
    cout << "Your option:";
    cin >> op;
    switch(op)
    {
        case '1':
            data.loadExtraGraph(25);
            OperationsMenu(3);
            break;
        case '2':
            data.loadExtraGraph(50);
            OperationsMenu(3);
            break;
        case '3':
            data.loadExtraGraph(75);
            OperationsMenu(3);
            break;
        case '4':
            data.loadExtraGraph(100);
            OperationsMenu(3);
            break;
        case '5':
            data.loadExtraGraph(200);
            OperationsMenu(3);
            break;
        case '6':
            data.loadExtraGraph(300);
            OperationsMenu(3);
            break;
        case '7':
            data.loadExtraGraph(400);
            OperationsMenu(3);
            break;
        case '8':
            data.loadExtraGraph(500);
            OperationsMenu(3);
            break;
        case '9':
            data.loadExtraGraph(600);
            OperationsMenu(3);
            break;
        case '10':
            data.loadExtraGraph(700);
            OperationsMenu(3);
            break;
        case '11':
            data.loadExtraGraph(800);
            OperationsMenu(3);
            break;
        case '12':
            data.loadExtraGraph(900);
            OperationsMenu(3);
            break;
        case 'q':
            mainMenu();
            break;
        default:
            cout << "Invalid Option..." << endl;
            ExtraFullyConnectedGraphsMenu();
            break;
    }
}

void Menu::OperationsMenu(int mode) {
    char op;
    cout << "__________________________________________\n";
    cout << "|               Operations               |\n";
    cout << "|        Choose one of the options       |\n";
    cout << "|________________________________________|\n";
    cout << "|      1. Backtracking Algorithm         |\n";
    cout << "|      2. Triangular Approximation       |\n";
    cout << "|      3. Other Heuristic                |\n";
    cout << "|      4. TSP in the Real World          |\n";
    cout << "|      \033[31mq. Go back \033[0m                       |\n";
    cout << "|________________________________________|\n";
    cout << "Your option:";
    cin >> op;
    switch(op)
    {
        case '1': {
            vector<int> tour;
            double a = backtracking(g,tour);
            for(auto x : tour){
                cout  << x << "->" << endl;
            }
            cout << "TOUR DISTANCE: " << a << endl;
            OperationsMenu(mode);
            break;
        }
        case '2':{
            double tourDistance;
            auto prism = primMST(g,tourDistance);
            for(auto z : prism){
                cout << z->getInfo() <<"->";
            }
            cout << endl;
            cout << "TOUR DISNTANCE: " << tourDistance<<endl;
            OperationsMenu(mode);
            break;
        }
        case '3':{
            vector<Vertex<int>*> path = nearestNeighbor(&g, 1);
            for (auto & i : path)
                cout << i->getInfo() << " ";
            cout << endl;
            cout << "Distance: " << calculateDistance(path) << endl;
            cout << "Number of vertices: " << g.getVertexSet().size() << endl;
            cout << "Number of visited cities: " << path.size() << endl;
            OperationsMenu(mode);
            break;
        }
        case '4': {
            cout << "Where do you want to start:";
            int start;
            cin >> start;
            runTSPAlgorithm(start);
            OperationsMenu(mode);
            break;
        }
        case 'q': {
            switch(mode)
            {
                case 1:
                    ToyGraphsMenu();
                    break;
                case 2:
                    RealworldGraphsMenu();
                    break;
                case 3:
                    ExtraFullyConnectedGraphsMenu();
                    break;
                default:
                    cout << "Invalid Option..." << endl;
                    OperationsMenu(mode);
                    break;
            }
            break;
        }
        default:
            cout << "Invalid Option..." << endl;
            OperationsMenu(mode);
            break;
    }
}

void Menu::runTSPAlgorithm(int start) {
    RealWorld realWorldSolver;
    auto result = realWorldSolver.solveTSP(g, start);

    if (result.first.size() != g.getNumVertex() + 1 || result.first.back() != start) {
        cout << "No path exists that visits all nodes and returns to the origin." << endl;
    }else {
        std::cout << "Best path: ";
        for (int vertex : result.first) {
            std::cout << vertex << " ";
        }
        std::cout << std::endl;
        std::cout << "Distance: " << result.second << std::endl;
    }
}

