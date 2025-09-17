class FoodRatings {
    struct Cmp {
        bool operator()(const pair<int,string>& a,
                        const pair<int,string>& b) const {
            if (a.first != b.first) return a.first > b.first; 
            return a.second < b.second;                      
        }
    };

    unordered_map<string, set<pair<int,string>, Cmp>> data; 
    unordered_map<string, string> foodToCuisine;            
    unordered_map<string, int>    foodToRating;           

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (size_t i = 0; i < foods.size(); ++i) {
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating [foods[i]] = ratings[i];
            data[cuisines[i]].emplace(ratings[i], foods[i]);
        }
    }

    void changeRating(string food, int newRating) {
        const string& c = foodToCuisine[food];
        int old = foodToRating[food];
        auto& st = data[c];
        st.erase({old, food});
        st.emplace(newRating, food);
        foodToRating[food] = newRating;
    }

    string highestRated(string cuisine) {
        const auto& st = data[cuisine];
        return st.empty() ? string() : st.begin()->second;
    }
};


/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */