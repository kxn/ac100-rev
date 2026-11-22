// func _wportal_db_aut_copy @ 0042b520 size=348

void _wportal_db_aut_copy(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    memcpy((void *)(param_1 + 0xc),(void *)(param_2 + 0xc),6);
    memcpy((void *)(param_1 + 0x14),(void *)(param_2 + 0x14),0x20);
    *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(param_2 + 0x108);
    *(undefined4 *)(param_1 + 0x10c) = *(undefined4 *)(param_2 + 0x10c);
    *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_2 + 0x3c);
    uVar1 = *(undefined4 *)(param_2 + 0x40);
    *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(param_2 + 0x44);
    *(undefined4 *)(param_1 + 0x40) = uVar1;
    memcpy((void *)(param_1 + 0x58),(void *)(param_2 + 0x58),0x28);
    *(undefined1 *)(param_1 + 0x80) = *(undefined1 *)(param_2 + 0x80);
    *(undefined1 *)(param_1 + 0x81) = *(undefined1 *)(param_2 + 0x81);
    memcpy((void *)(param_1 + 0x82),(void *)(param_2 + 0x82),0x21);
    memcpy((void *)(param_1 + 0xa3),(void *)(param_2 + 0xa3),0x65);
    memcpy((void *)(param_1 + 0x34),(void *)(param_2 + 0x34),6);
    uVar1 = *(undefined4 *)(param_2 + 0x48);
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_2 + 0x4c);
    *(undefined4 *)(param_1 + 0x48) = uVar1;
    uVar1 = *(undefined4 *)(param_2 + 0x50);
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_2 + 0x54);
    *(undefined4 *)(param_1 + 0x50) = uVar1;
    *(undefined4 *)(param_1 + 0x140) = *(undefined4 *)(param_2 + 0x140);
    *(undefined4 *)(param_1 + 0x144) = *(undefined4 *)(param_2 + 0x144);
    *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(param_2 + 0x148);
    *(undefined4 *)(param_1 + 0x154) = *(undefined4 *)(param_2 + 0x154);
    *(undefined4 *)(param_1 + 0x158) = *(undefined4 *)(param_2 + 0x158);
    uVar1 = *(undefined4 *)(param_2 + 0x160);
    *(undefined4 *)(param_1 + 0x164) = *(undefined4 *)(param_2 + 0x164);
    *(undefined4 *)(param_1 + 0x160) = uVar1;
    *(undefined4 *)(param_1 + 0x168) = *(undefined4 *)(param_2 + 0x168);
    *(undefined4 *)(param_1 + 0x16c) = *(undefined4 *)(param_2 + 0x16c);
    *(undefined4 *)(param_1 + 0x14c) = *(undefined4 *)(param_2 + 0x14c);
    uVar1 = *(undefined4 *)(param_2 + 0x170);
    *(undefined4 *)(param_1 + 0x174) = *(undefined4 *)(param_2 + 0x174);
    *(undefined4 *)(param_1 + 0x170) = uVar1;
    uVar1 = *(undefined4 *)(param_2 + 0x178);
    *(undefined4 *)(param_1 + 0x17c) = *(undefined4 *)(param_2 + 0x17c);
    *(undefined4 *)(param_1 + 0x178) = uVar1;
  }
  return;
}

