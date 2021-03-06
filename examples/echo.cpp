#include <coronet.hpp>

int main() {
    coronet coro;
    coro.listen("0.0.0.0", 1234, [&](int fd) {
        auto& in = coro.get_istream(fd);
        auto& out = coro.get_ostream(fd);
        coro.set_timeout(fd, std::chrono::seconds(0));
        std::string data;
        while (std::getline(in, data)) {
            out << data << std::endl;
        }
        coro.close(fd);
    });
    coro.run();
}
