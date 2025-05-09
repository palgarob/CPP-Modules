The Ford-Johnson algorithm (also known as Merge-Insertion Sort) is a comparison sorting algorithm that is more efficient than standard comparison-based algorithms in terms of the number of comparisons made. It’s particularly interesting because it uses the Jacobsthal sequence and binary search to optimize insertion steps.

Here’s a step-by-step breakdown of how to implement it, including an explanation of the Jacobsthal sequence, binary search, and recursion use. We’ll also use C++ code snippets to illustrate.

⸻

🔢 Step-by-Step Implementation of Ford-Johnson Algorithm

⸻

Step 1: Understand the Jacobsthal Sequence

The Jacobsthal sequence is defined recursively as:
	•	J(0) = 0
	•	J(1) = 1
	•	J(n) = J(n - 1) + 2 * J(n - 2) for n ≥ 2

We’ll use it to determine the optimal order of inserting remaining elements into the main chain.

int jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}



⸻

Step 2: Split the Input into Pairs

Group the elements into pairs and sort each pair. If there is an odd number of elements, leave the last one as a singleton.

std::vector<std::pair<int, int>> make_pairs(const std::vector<int>& input) {
    std::vector<std::pair<int, int>> pairs;
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        if (input[i] < input[i+1])
            pairs.emplace_back(input[i], input[i+1]);
        else
            pairs.emplace_back(input[i+1], input[i]);
    }
    // Singleton element (if any) is handled later
    return pairs;
}



⸻

Step 3: Sort the Larger Elements Recursively

From each pair (a, b), take the larger element (i.e., b) and sort them recursively using the Ford-Johnson algorithm itself. This is where recursion is applied.

std::vector<int> extract_larger(const std::vector<std::pair<int, int>>& pairs) {
    std::vector<int> larger;
    for (const auto& p : pairs)
        larger.push_back(p.second);
    return larger;
}

Call the recursive sort:

std::vector<int> sorted_larger = ford_johnson_sort(extract_larger(pairs));



⸻

Step 4: Insert the Smaller Elements Using Binary Search

Now, insert the smaller elements (from each pair) into the sorted list of larger elements, using binary search to find the correct position for each.

std::vector<int> extract_smaller(const std::vector<std::pair<int, int>>& pairs) {
    std::vector<int> smaller;
    for (const auto& p : pairs)
        smaller.push_back(p.first);
    return smaller;
}



⸻

What is Binary Search and How It’s Used?

Binary search is a search algorithm that finds the position of a target value within a sorted array by repeatedly dividing the search interval in half.

In Ford-Johnson, binary search is used to find the correct index to insert a new element into the sorted array, ensuring the array remains sorted.

int binary_search_insert_position(const std::vector<int>& sorted, int value) {
    int left = 0, right = sorted.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (sorted[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}



⸻

Step 5: Determine Insertion Order Using Jacobsthal

Use the Jacobsthal sequence to determine the order of insertion for the smaller elements into the main chain.

std::vector<int> generate_jacobsthal_order(int n) {
    std::vector<int> order;
    std::set<int> seen;

    int i = 1;
    while (true) {
        int j = jacobsthal(i);
        if (j >= n) break;
        if (!seen.count(j)) {
            order.push_back(j);
            seen.insert(j);
        }
        ++i;
    }

    for (int i = 0; i < n; ++i) {
        if (!seen.count(i))
            order.push_back(i);
    }

    return order;
}



⸻

Step 6: Perform Insertions

Now, insert the smaller elements into the sorted list of larger elements using the Jacobsthal-based insertion order and binary search.

for (int index : generate_jacobsthal_order(smaller.size())) {
    int value = smaller[index];
    int pos = binary_search_insert_position(sorted_larger, value);
    sorted_larger.insert(sorted_larger.begin() + pos, value);
}



⸻

Step 7: Insert Singleton (if any)

If there was a leftover unpaired singleton from the beginning, insert it now with binary search.

if (input.size() % 2 == 1) {
    int singleton = input.back();
    int pos = binary_search_insert_position(sorted_larger, singleton);
    sorted_larger.insert(sorted_larger.begin() + pos, singleton);
}



⸻

✅ Final Function

std::vector<int> ford_johnson_sort(const std::vector<int>& input) {
    if (input.size() <= 1)
        return input;

    auto pairs = make_pairs(input);
    auto smaller = extract_smaller(pairs);
    auto sorted_larger = ford_johnson_sort(extract_larger(pairs)); // recursive call

    for (int idx : generate_jacobsthal_order(smaller.size())) {
        int val = smaller[idx];
        int pos = binary_search_insert_position(sorted_larger, val);
        sorted_larger.insert(sorted_larger.begin() + pos, val);
    }

    if (input.size() % 2 == 1) {
        int singleton = input.back();
        int pos = binary_search_insert_position(sorted_larger, singleton);
        sorted_larger.insert(sorted_larger.begin() + pos, singleton);
    }

    return sorted_larger;
}



⸻

🔁 Where Recursion is Used:
	•	In ford_johnson_sort(), we recursively sort the “larger” elements.
	•	This recursion continues until the base case (size <= 1) is reached.

⸻

Would you like a visual diagram to show how this algorithm works step-by-step on an example input?
