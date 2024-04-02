

public class QuickUnionDS implements DisjointSets {

	private int[] parent;
	private int[] weight;

	public QuickUnionDS(int num) {
		parent = new int[num];
		weight = new int[num];
		for (int i = 0; i < num; i += 1) {
			parent[i] = i;
			weight[i] = 1;
		}

	}

	private int find(int p) {
		while (parent[p] >= 0) {
			p = parent[p];
		}
		return p;
	}

	@Override
	public void connect(int p, int q) {
		int pid = find(p);
		int qid = find(q);

		if (pid == qid) {
            return; // They are already connected
        }

		if (weight[pid] < weight[qid]) {
			// smaller tree be child
			parent[pid] = qid;
			// larger tree add weight
			weight[qid] += weight[pid];
		} else {
			parent[qid] = pid;
			weight[pid] += weight[qid];
		}
	}

	@Override
	public boolean isConnected(int p, int q) {
		return find(p) == find(q);
	}
}
