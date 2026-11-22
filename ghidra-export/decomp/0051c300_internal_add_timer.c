// func internal_add_timer @ 0051c300 size=352

void internal_add_timer(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined *puVar5;
  
  uVar2 = *(uint *)(param_1 + 0x5c);
  uVar3 = uVar2 - DAT_007822e0;
  uVar1 = uVar2;
  if (0xff < uVar3) {
    if (uVar3 < 0x4000) {
      uVar1 = (uVar2 << 0x12) >> 0x1a;
      puVar5 = &DAT_00782ee4 + uVar1 * 0xc;
      uVar4 = 2;
      goto LAB_0051c35c;
    }
    if (uVar3 < 0x100000) {
      uVar1 = (uVar2 << 0xc) >> 0x1a;
      puVar5 = &DAT_007831e4 + uVar1 * 0xc;
      uVar4 = 3;
      goto LAB_0051c35c;
    }
    if (uVar3 < 0x4000000) {
      uVar1 = (uVar2 << 6) >> 0x1a;
      puVar5 = &DAT_007834e4 + uVar1 * 0xc;
      uVar4 = 4;
      goto LAB_0051c35c;
    }
    uVar1 = DAT_007822e0;
    if (-1 < (int)uVar3) {
      uVar1 = uVar2 >> 0x1a;
      puVar5 = &DAT_007837e4 + uVar1 * 0xc;
      uVar4 = 5;
      goto LAB_0051c35c;
    }
  }
  uVar1 = uVar1 & 0xff;
  puVar5 = &DAT_007822e4 + uVar1 * 0xc;
  uVar4 = 1;
LAB_0051c35c:
  if (wheel_md5_timer_debug_switch != '\0') {
    printf("[WHEEL_MD5_TIMER_DEBUG]%s()/%d Timer %d(expire: %lu ticks) Insert to [%d:%d].\n",
           "internal_add_timer",0x125,*(undefined4 *)(param_1 + 0xc),uVar2,uVar4,uVar1);
  }
  uac_list_insert_last(puVar5,param_1);
  return;
}

