#include "utils.h"
#include <chrono>
#include <ctime>
#include <sstream>
#include <thread> 


// copiei da internet essa funcao e pra pegar o tempo do sistema
std::string obterHoraAtual() {
    // Obtém o tempo atual
    auto now = std::chrono::system_clock::now();

    // Converte para time_t para usar com std::ctime
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    // Converte time_t para string
    std::stringstream ss;
    ss << std::ctime(&now_time);
    
    // Retorna a string com a hora atual
    return ss.str();
}

// copiei função sleep que recebe o número de segundos para esperar
void sleep(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

