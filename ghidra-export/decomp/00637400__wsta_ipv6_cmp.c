// func _wsta_ipv6_cmp @ 00637400 size=136

undefined4 _wsta_ipv6_cmp(int param_1,void *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 local_44 [28];
  undefined1 local_28 [28];
  
  uVar1 = 0;
  if ((param_1 != 0) && (param_2 != (void *)0x0)) {
    memcpy(local_28,param_2,0x14);
    for (uVar2 = 0; uVar2 < 0x14; uVar2 = uVar2 + 1) {
      local_44[uVar2] = local_28[uVar2];
    }
    uVar1 = FUN_004085c0(*(undefined4 *)(param_1 + 0x50),*(undefined4 *)(param_1 + 0x54),
                         *(undefined4 *)(param_1 + 0x58),*(undefined4 *)(param_1 + 0x5c),
                         *(undefined4 *)(param_1 + 0x60));
  }
  return uVar1;
}

