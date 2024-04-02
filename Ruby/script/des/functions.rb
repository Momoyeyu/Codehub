# functions.rb
require_relative 'constants'
require_relative 'helper'

# ip_replace: IP_TABLE, IPR_TABLE
# generate_key: PC1_TABLE, PC2_TABLE, LOOP_TABLE
# e_extend: E_TABLE
# s_box_replace: S_BOX
# p_substitute: P_BOX

def ip_replace(bitset)
  return replace(bitset, IP_TABLE)
end

def ip_reverse(cipher_chunk)
  return replace(cipher_chunk, IPR_TABLE)
end

def f_func(right, keys, round)
  tmp = xor_arr(e_extend(right), keys[round])
  tmp = s_box_replace(tmp, round)
  return p_box_replace(tmp)
end

def e_extend(right)
  return replace(right, E_TABLE)
end

def s_box_replace(input, round)
  result = Array.new()
  8.times do |i|
    row = bits_to_int([input[i * 6], input[i * 6 + 5]])
    col = bits_to_int(input[i * 6 + 1, 4]) # [start, step]
    result += int_to_bits(S_BOX[round % 8][row][col], 4)
  end
  return result
end

def p_box_replace(input)
  return replace(input, P_BOX)
end

def generate_key(key)
  keys = Array.new(16){Array.new(48)}
  tmp = pc1_replace(key)
  left, right = tmp[0, 28], tmp[28, 28]
  for i in 0..15
    left = left.rotate(LOOP_TABLE[i])
    right = right.rotate(LOOP_TABLE[i])
    keys[i] = pc2_replace(left + right)
  end
  return keys
end

def pc1_replace(key)
  return replace(key, PC1_TABLE)
end

def pc2_replace(key)
  return replace(key, PC2_TABLE)
end

# test
# p pc1_replace([1, 2, 3, 4])
