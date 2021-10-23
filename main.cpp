#include <iostream>
#include <string>
#include <vector>
#define x 1
#define y 2
#define z 3
#define h 4

std::string shift_operation(std::string s,int k){
    std::string buf;
    for (int i = 0; i < s.length(); i++){
        buf += char(s[i]-k);
    }
    return buf;
}

void shift(const int s) {
    std::string x_s = "Zpvs!mphjo;!";
    std::string y_s = "[qwt\"rcuuyqtf<\"";
    std::string z_s = "Dffhvv#doorzhg$";
    std::string h_s = "Eggiww$hirmih%$Mrzepmh$teww{svh%";
    if (s == 1) {
        std::cout << shift_operation(x_s, s) << std::endl;
    } else if (s == 2) {
        std::cout << shift_operation(y_s, s) << std::endl;
    } else if (s == 3) {
        std::cout << shift_operation(z_s, s) << std::endl;
    } else if (s == 4) {
        std::cout << shift_operation(h_s, s) << std::endl;
    }
}

std::string phash(const std::string s) {
    std::string code;
    std::string res;
    int buf;
    std::vector<int> num;
    for (int i = 0; i < s.length(); i++) {
        code += std::to_string(int(s[i]));
        buf+=1;
        if (s[i] == ' ')
            break;
    }
    if (code.length()%2 != 0){
        code = code + '0';
        buf+=1;
    }

    for (int i = 0; i < code.length()-1; i+=2){
        std::string tmp = "";
        tmp += code.at(i);
        tmp += code.at(i + 1);
        num.push_back(std::stoi(tmp));
    }

    for (int i = 0; i < num.size(); i++){
        res += char((num[i] % 75) + 48);
    }
    buf = 0;
    return res;
}


int main(){
    std::string a, b, c;
    shift(x);
    std::cin >> a;
    shift(y);
    std::cin >> b;
    if (b == phash(a)){
        shift(z);
    }
    else {
        shift(h);
    }
}





