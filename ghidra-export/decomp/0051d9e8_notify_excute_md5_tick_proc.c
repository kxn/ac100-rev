// func notify_excute_md5_tick_proc @ 0051d9e8 size=432

void notify_excute_md5_tick_proc(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = DAT_007822e0;
  uac_mutex_take(g_wheel_md5_timer_base,0xffffffff);
  if ((uVar1 & 0xff) == 0) {
    iVar2 = cascade(&DAT_00782ee4,(uVar1 << 0x12) >> 0x1a);
    if (iVar2 == 0) {
      iVar2 = cascade(&DAT_007831e4,(uVar1 << 0xc) >> 0x1a);
      if (iVar2 == 0) {
        iVar2 = cascade(&DAT_007834e4,(uVar1 << 6) >> 0x1a);
        if (iVar2 == 0) {
          cascade(&DAT_007837e4,uVar1 >> 0x1a);
        }
      }
    }
  }
  DAT_007822e0 = DAT_007822e0 + 1;
  iVar2 = uac_list_size(&DAT_007822e4 + (uVar1 & 0xff) * 0xc);
  if (iVar2 != 0) {
    uac_mutex_take(DAT_007822d8,0xffffffff);
    while (iVar2 = uac_list_first(&DAT_007822e4 + (uVar1 & 0xff) * 0xc), iVar2 != 0) {
      *(byte *)(iVar2 + 0x54) = *(byte *)(iVar2 + 0x54) | 4;
      uac_list_remove(iVar2);
      uac_list_insert_last(&DAT_00783af4,iVar2);
    }
    uac_cond_signal(DAT_007822dc);
    uac_mutex_give(DAT_007822d8);
  }
  uac_mutex_give(g_wheel_md5_timer_base);
  return;
}

