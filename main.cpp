#include <iostream>
#include <unordered_map>
#include <sstream>
#include <regex>
#include <string>

// Função que conta a frequência das palavras em um texto
std::unordered_map<std::string, int> contarPalavras(const std::string& texto) {
    std::unordered_map<std::string, int> frequencia;
    std::regex palavraRegex(R"(\b\w+\b)");
    auto palavrasInicio = std::sregex_iterator(texto.begin(), texto.end(), palavraRegex);
    auto palavrasFim = std::sregex_iterator();

    for (std::sregex_iterator i = palavrasInicio; i != palavrasFim; ++i) {
        std::string palavra = i->str();
        ++frequencia[palavra];
    }
    return frequencia;
}

int main() {
    std::cout << "🔍 Word Frequency Analyzer (EN-CA)\n\n";
    std::cout << "Enter a sentence or paragraph:\n> ";

    std::string entrada;
    std::getline(std::cin, entrada);

    auto resultado = contarPalavras(entrada);

    std::cout << "\n📊 Frequency Table:\n";
    for (const auto& [palavra, contagem] : resultado) {
        std::cout << " - " << palavra << ": " << contagem << "\n";
    }

    std::cout << "\n✨ Analysis complete. Coded with 💙 by MSP 2025.\n";
    return 0;
}
