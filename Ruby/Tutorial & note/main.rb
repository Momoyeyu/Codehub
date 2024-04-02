require "date"
days = Date.today - Date.new(1993, 2, 24)
puts(days.to_i)

require "pp"  # pretty print
puts "pp print:"
books = [
  { title: "nukidasi", ctg: "gal" },
  { title: "tsukiyoruotome", ctg: "gal" },
  { title: "howaitoarubamunn", ctg: "novel"}
]
pp books
puts "p print:"
p books

require_relative "hello"
hello()

# tested require and require_relative

require_relative "grep"
pattern = Regexp.new(ARGV[0])
filename = ARGV[1]
simple_grep(pattern, filename)

