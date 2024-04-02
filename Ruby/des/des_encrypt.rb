# des.rb

require_relative 'functions'
require_relative 'helper'

# encryption
def encryption(message, key)
  bitset = string_to_bitset_i(message)
  # fill the rest as 0
  ((64 - (bitset.length % 64)) % 64).times do
    bitset.append(0)
  end
  while key.length < 8
    key += 0.chr
  end
  key = key[0, key.length]
  keys = generate_key(string_to_bitset_i(key))

  round = bitset.length / 64
  result = Array.new

  round.times do |i|
    result += encrypt(bitset[i * 64, 64], keys)
  end

  return result
end

def encrypt(chunk, keys)
  result = ip_replace(chunk)
  left, right = result[0, 32], result[32, 32]
  16.times do |round|
    ki = f_func(right, keys, round)
    left, right = right, xor_arr(left, ki)
  end
  return ip_reverse(right + left)
end

# main
print "message: "
message = gets()
print "key: "
key = gets()

cipher = encryption(message, key)
cipher = bitset_to_string(cipher)
print "cipher (not inluce {{}}): {{", cipher, "}}\n"
print "code: "
pp cipher
