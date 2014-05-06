def chinese_remainder(a, m)
	n = a.size
	r = m.reduce(1, :*)
	p = m.map {|v| r / v }
	y = Array.new(n) {|i| (euclid_extended(p[i], m[i])[1] + m[i]) % m[i]}
	(0...n).reduce(0) {|x, i| (x + a[i] * p[i] * y[i]) % r }
end