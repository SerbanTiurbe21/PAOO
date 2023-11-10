#include <vector>
#include <stdexcept>

namespace Aviation{
    template <typename ItemType>
    class CargoHolder{
        private:
            std::vector<ItemType> items;
            size_t capacity;
        public:
            CargoHolder(size_t capacity) : capacity(capacity) {}
            ~CargoHolder() {}

            void addItem(const ItemType& item) {
                if (items.size() >= capacity) {
                    throw std::runtime_error("CargoHolder is full");
                }
                items.push_back(item);
            }

            bool removeItem(const ItemType& item) {
                auto it = std::find(items.begin(), items.end(), item);
                if (it != items.end()) {
                    items.erase(it);
                    return true;
                }
                return false;
            }

            size_t getItemCount() const {
                return items.size();
            }

            size_t getCapacity() const {
                return capacity;
            }
    };
}