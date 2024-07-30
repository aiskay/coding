#pragma once

#include <deque>
#include <memory>
#include <unordered_set>
#include <unordered_map>

// 途中まで書いたけど、unary_function は非推奨だったりして怪しい

template<typename T>
struct WeakPtrHash: public std::unary_function<std::weak_ptr<T>, size_t>
{
    size_t operator()( const std::weak_ptr<T>& wp ) const
    {
        auto sp = wp.lock();
        return std::hash<decltype(sp)>()(sp);
    }
};

template<typename T>
struct WeakPtrEqual : public std::unary_function<std::weak_ptr<T>, bool>
{

};


template <typename State>
class Graph
{
    private:
            std::deque<std::shared_ptr<Node>> nodes;
            std::unordered_map<std::string, std::shared_ptr<Node>> namedNodes;

    public:
        class Node
        {
            private:
                std::unordered_set<std::weak_ptr<Node>, WeakPtrHash<Node>, WeakPtrEqual<Node>> childs;
            
            public:
                Node( const std::string &n ): name(n) {}
                virtual ~Node() {}

                bool isAdjacentFor( const std::shared_ptr<Node>& other ) const
                { return childs.find(other) != childs.end(); }
                void addChild( const std::shared_ptr<Node>& other ) { return childs.insert(other); }
                const std::unordered_map<std::weak_ptr<Node>, WeakPtrHash<Node>, WeakPtrEqual<Node>>&
                getAdjacent() const { return childs; }
                const std::string& Name() const { return name; }
                
                mutable State state;
                std::string name;
        }
    

};