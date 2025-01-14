auto MOS6502::algorithmADC(n8 i) -> n8 {
  i16 o;
  if(!BCD || !D) {
    o = A + i + C;
    V = ~(A ^ i) & (A ^ o) & 0x80;
  } else {
    idle();
    o = (A & 0x0f) + (i & 0x0f) + (C << 0);
    if(o > 0x09) o += 0x06;
    C = o > 0x0f;
    o = (A & 0xf0) + (i & 0xf0) + (C << 4) + (o & 0x0f);
    if(o > 0x9f) o += 0x60;
  }
  C = o.bit(8);
  Z = n8(o) == 0;
  N = o.bit(7);
  return o;
}

auto MOS6502::algorithmAND(n8 i) -> n8 {
  n8 o = A & i;
  Z = o == 0;
  N = o.bit(7);
  return o;
}

auto MOS6502::algorithmASL(n8 i) -> n8 {
  C = i.bit(7);
  i <<= 1;
  Z = i == 0;
  N = i.bit(7);
  return i;
}

auto MOS6502::algorithmBIT(n8 i) -> n8 {
  Z = (A & i) == 0;
  V = i.bit(6);
  N = i.bit(7);
  return A;
}

auto MOS6502::algorithmCMP(n8 i) -> n8 {
  n9 o = A - i;
  C = !o.bit(8);
  Z = n8(o) == 0;
  N = o.bit(7);
  return A;
}

auto MOS6502::algorithmCPX(n8 i) -> n8 {
  n9 o = X - i;
  C = !o.bit(8);
  Z = n8(o) == 0;
  N = o.bit(7);
  return X;
}

auto MOS6502::algorithmCPY(n8 i) -> n8 {
  n9 o = Y - i;
  C = !o.bit(8);
  Z = n8(o) == 0;
  N = o.bit(7);
  return Y;
}

auto MOS6502::algorithmDEC(n8 i) -> n8 {
  i--;
  Z = i == 0;
  N = i.bit(7);
  return i;
}

auto MOS6502::algorithmEOR(n8 i) -> n8 {
  n8 o = A ^ i;
  Z = o == 0;
  N = o.bit(7);
  return o;
}

auto MOS6502::algorithmINC(n8 i) -> n8 {
  i++;
  Z = i == 0;
  N = i.bit(7);
  return i;
}

auto MOS6502::algorithmLD(n8 i) -> n8 {
  Z = i == 0;
  N = i.bit(7);
  return i;
}

auto MOS6502::algorithmLSR(n8 i) -> n8 {
  C = i.bit(0);
  i >>= 1;
  Z = i == 0;
  N = i.bit(7);
  return i;
}

auto MOS6502::algorithmORA(n8 i) -> n8 {
  n8 o = A | i;
  Z = o == 0;
  N = o.bit(7);
  return o;
}

auto MOS6502::algorithmROL(n8 i) -> n8 {
  bool c = C;
  C = i.bit(7);
  i = i << 1 | c;
  Z = i == 0;
  N = i.bit(7);
  return i;
}

auto MOS6502::algorithmROR(n8 i) -> n8 {
  bool c = C;
  C = i.bit(0);
  i = c << 7 | i >> 1;
  Z = i == 0;
  N = i.bit(7);
  return i;
}

auto MOS6502::algorithmSBC(n8 i) -> n8 {
  i = ~i;
  i16 o;
  if(!BCD || !D) {
    o = A + i + C;
    V = ~(A ^ i) & (A ^ o) & 0x80;
  } else {
    idle();
    o = (A & 0x0f) + (i & 0x0f) + (C << 0);
    if(o <= 0x0f) o -= 0x06;
    C = o > 0x0f;
    o = (A & 0xf0) + (i & 0xf0) + (C << 4) + (o & 0x0f);
    if(o <= 0xff) o -= 0x60;
  }
  C = o.bit(8);
  Z = n8(o) == 0;
  N = o.bit(7);
  return o;
}

auto MOS6502::algorithmSLO(n8 i) -> n8 {
  C = i.bit(7);
  i <<= 1;

  n8 o = A | i;
  Z = o == 0;
  N = o.bit(7);
  return o;
}