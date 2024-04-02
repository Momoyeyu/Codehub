
def euclid_gcd(a, b):
	'''
	@expression:
		sa + tb = (a, b)
	@params:
		a: param 1
		b: param 2
	@return:
		s: factor of a
		t: factor of b
		gcd: greatest common factor
	'''
	q = a // b
	r = a % b
	if r == 0:
		return (0, 1, b)
	m, n, gcd = euclid_gcd(b, r)
	s = n
	t = m - n * q
	return (s, t, gcd)

data = [(5, 462), (6, 385), (7, 330), (11, 210)]
for a, b in data:
	print("[INPUT] (a, b) = ({}, {})".format(a, b))
	s, t, gcd = euclid_gcd(a, b)
	print("[OUTPUT] (s, t, gcd) = ({}, {}, {})".format(s, t, gcd))
	print("[EXPRESSION] s*a + t*b = (a, b) => {} * {} + {} * {} = {}".format(s, a, t, b, gcd))
	print()


