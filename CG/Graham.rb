def graham(points)
	return points if points.size < 3
	points = points.sort {|lhs, rhs| lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y)}
	upper = [points[1], points[0]]
	points[2..-1].each do |point|
		upper.shift while upper.size >= 2 and direct(upper[1], upper[0], point) != RIGHT
		upper.unshift(point)
	end
	points.reverse!
	lower = [points[1], points[0]]
	points[2..-1].each do |point|
		lower.shift while upper.size >= 2 and direct(lower[1], lower[0], point) != RIGHT
		lower.unshift(point)
	end
	upper.shift.reverse! + lower.shift.reverse!
end