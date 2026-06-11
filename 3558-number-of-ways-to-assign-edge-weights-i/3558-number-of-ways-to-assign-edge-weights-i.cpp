static constexpr int N=1e5;
static int q[N], front=0, back=0;// queue q
static int adj[N+1]={[1 ... N]=-1};// array linked list
struct Edge{
    int to=-1, nxt=-1;
};
Edge E[2*N];
int eCnt=0;
static inline void addEdge(int u, int v){
    E[eCnt]={v, adj[u]};
    adj[u]=eCnt++;
}
static const int mod=1e9+7;
class Solution {
public:
    static long long modPow(long long x, int exp) {
        long long y=1; 
        for(; exp; exp>>=1){
            y=(exp&1)?y*x%mod:y;
            x=x*x%mod;
        }
        return y;
    }
    static long long pow2(int x) {
        if (x < 30)
            return 1<<x;
        long long B = (1<<30) % mod;
        auto [qq, r] = div(x, 30);
        return modPow(B, qq)*pow2(r)%mod;
    }
    static int assignEdgeWeights(vector<vector<int>>& edges) {
        const int n=edges.size()+1;
        memset(adj+1, -1, sizeof(int)*n);
        eCnt=0;
        for (auto& e : edges) {
            int u=e[0], v=e[1];
            addEdge(u, v);
            addEdge(v, u);
        }
        front=back=0;// q reset
        bitset<N+1> viz=0;
        q[back++]=1;
        viz[1]=1;
        int depth=-1;
        for(; front<back; depth++){
            int qz=back-front;
            while(qz--){
                int u=q[front++];
                viz[u]=1;
                for(int e=adj[u]; e!=-1; e=E[e].nxt) {
                    int v=E[e].to;
                    if (viz[v]) continue;
                    viz[v]=1;
                    q[back++]=v;
                }
            }
        }
        return pow2(depth-1);
    }
};