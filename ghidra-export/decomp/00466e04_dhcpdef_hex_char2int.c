// func dhcpdef_hex_char2int @ 00466e04 size=44

undefined1 dhcpdef_hex_char2int(int param_1)

{
  undefined1 uVar1;
  uint uVar2;
  
  uVar2 = param_1 - 0x31U & 0xff;
  uVar1 = 0;
  if (uVar2 < 0x36) {
    uVar1 = (&DAT_0068e5b0)[uVar2];
  }
  return uVar1;
}

