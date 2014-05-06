def euclid_extended(a, b)
	if b.zero?
		[a, 1, 0]
	else
		tmp = euclid_extended(b, a % b)
		[tmp[0], tmp[2], tmp[1] - a / b * tmp[2]]
	end
end