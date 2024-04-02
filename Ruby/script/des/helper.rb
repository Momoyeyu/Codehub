# helper.rb

def string_to_bitset_i(string)
  len = string.length
  bitset = Array.new(len * 8)
  bit = 0
  len.times do |i|
    bits = string[i].ord.to_s(2)
    (8 - bits.length).times do
      bitset[bit] = 0
      bit += 1
    end
    bits.length.times do |j|
      bitset[bit] = bits[j].to_i
      bit += 1
    end
  end
  return bitset
end

def string_to_bitset_s(string)
  bitset = ""
  string.length.times do |i|
    bits = string[i].ord.to_s(2)
    (8 - bits.length).times do
      bitset += "0"
    end
    bitset += bits
  end
  return bitset
end

def bitset_to_string(bitset)
  string = ""
  (bitset.length / 8).times do |i|
    byte = bitset[i * 8, (i + 1) * 8]
    char = 0
    power = 128
    8.times do |bit|
      char += byte[bit].to_i * power
      power /= 2
    end
    string += char.chr
  end
  return string
end

def xor_arr(x, y)
  result = Array.new(x.length)
  x.length.times do |i|
    result[i] = x[i] ^ y[i]
  end
  return result
end

def replace(input, table)
  size = table.size
  result = Array.new(size)
  for i in 0..(size - 1)
    result[i] = input[table[i] - 1]
  end
  return result
end

def int_to_bits(int, len)
  int %= (2 ** len)
  result = Array.new(len, 0)
  while len > 0
    len -= 1
    result[len] = int % 2
    int /= 2
  end
  return result
end

def bits_to_int(bits)
  result = 0
  power = 1
  while !bits.empty?
    result += bits.pop() * power
    power *= 2
  end
  return result
end
