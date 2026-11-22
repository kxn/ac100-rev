// func _wsta_del_sta_timer_handle @ 00637138 size=712

void _wsta_del_sta_timer_handle(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint extraout_v1;
  int iVar6;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  if ((g_wsta_warning != 0) && (iVar2 = is_target_debug_ap(&local_38), iVar2 != 0)) {
    printf("<wsta>[warning]%s(): %d  -> del sta time start\r\n","_wsta_del_sta_timer_handle",0x38f);
  }
  FUN_0051ad88(&local_38);
  FUN_004082d0(DAT_007cc6bc,0xffffffff);
  iVar2 = FUN_004081b0(&DAT_007cc71c);
  if ((g_wsta_warning != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
    uVar5 = FUN_00407fe0(&DAT_007cc71c);
    printf("<wsta>[warning]%s(): %d  -> -----SIZE:%d.\n\r\n","_wsta_del_sta_timer_handle",0x395,
           uVar5);
  }
  iVar6 = 0x186a1;
  while ((iVar1 = iVar2, iVar1 != 0 && (iVar6 = iVar6 + -1, iVar6 != 0))) {
    iVar2 = FUN_00408680(iVar1);
    FUN_00407e70();
    if (g_wsta_debug == 0) {
      uVar3 = *(uint *)(iVar1 + 0x24);
    }
    else {
      iVar4 = is_target_debug_ap();
      uVar3 = *(uint *)(iVar1 + 0x24);
      if (iVar4 != 0) {
        printf("<wsta>[debug]%s(): %d  -> curtime:%d, leave_time:%d.\n\r\n",
               "_wsta_del_sta_timer_handle",0x39c,extraout_v1,uVar3);
        uVar3 = *(uint *)(iVar1 + 0x24);
      }
    }
    if (extraout_v1 < uVar3) {
      uVar3 = ~uVar3;
    }
    else {
      uVar3 = -uVar3;
    }
    if (4 < extraout_v1 + uVar3) {
      iVar4 = FUN_00407f40(DAT_007cc718,iVar1 + -0xc);
      if (iVar4 == 0) {
        FUN_00408500(iVar1);
        wsta_free(iVar1 + -0xc);
      }
      else if ((g_wsta_error != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("<wsta>[error]%s(): %d  -> uac_hash_remove() fail, wsta_entry->id=%d!\r\n",
               "_wsta_del_sta_timer_handle",0x3a2,*(undefined4 *)(iVar1 + 0x10));
      }
    }
  }
  iVar6 = -1;
  iVar2 = FUN_00407ed0(DAT_007cc718);
  if ((((0 < iVar2) &&
       (iVar6 = FUN_00408340(5,0,_wsta_del_sta_timer_handle,0,0,"_wsta_del_sta_timer_handle",0x3af),
       iVar6 == -1)) && (g_wsta_error != 0)) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("<wsta>[error]%s(): %d  -> uac_timer_add() fail!\r\n","_wsta_del_sta_timer_handle",0x3b2)
    ;
  }
  DAT_007cc714 = iVar6;
  FUN_00407f30(DAT_007cc6bc);
  return;
}

