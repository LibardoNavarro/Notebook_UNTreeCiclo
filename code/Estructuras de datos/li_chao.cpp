// inf max abs value that the function may take
typedef long long ty;

struct Line {
	ty m, b;

	Line(){}
	Line(ty m, ty b): m(m), b(b){}

	ty eval(ty x){return m * x + b;}
};

struct nLiChao{
	// see coments for min

	nLiChao *left = nullptr, *right = nullptr;
	ty l, r;
	Line line;

	nLiChao(ty l, ty r): l(l), r(r){
		line = {0, -inf}; // change to {0, inf};
	}

	// T(Log(Rango)) M(Log(rango))
	void addLine(Line nline){
		ty m = (l + r) >> 1;
		bool lef = nline.eval(l) > line.eval(l); // change > to <
		bool mid = nline.eval(m) > line.eval(m); // change > to <

		if (mid) swap(nline, line);

		if (r == l) return;

		if (lef != mid){
			if (!left){
				left = new nLiChao(l, m);
				left -> line = nline;
			}

			else left -> addLine(nline);
		}
		else{
			if (!right){
				right = new nLiChao(m + 1, r);
				right -> line = nline;
			}

			else right -> addLine(nline);
		}
	}

	// T(Log(Rango))
	ty get(ty x) {
		ty m = (l + r) >> 1;
		ty op1 = -inf, op2 = -inf; // change to inf		

		if(l == r) return line.eval(x);
		else if(x < m){
			if (left) op1 = left -> get(x);
			return max(line.eval(x), op1); // change max to min
		} 
		else{
			if (right) op2 = right -> get(x);
			return max(line.eval(x), op2); // change max to min
		}
	}
};


int main() {
	// (rango superior) * (pendiente maxima) puede desbordarse
	// usar double o long double en el eval para estos casos 
	// (puede dar problemas de precision)
	nLiChao liChao(0, 1e18);
}