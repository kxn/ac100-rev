// func _wsta_idle_timer_handle @ 0063e1dc size=1192

void _wsta_idle_timer_handle(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint extraout_v1;
  void *__s1;
  int iVar5;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 auStack_68 [12];
  undefined1 auStack_5c [6];
  byte local_56;
  undefined1 auStack_52 [34];
  int local_30;
  
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  memset(auStack_68,0,0x38);
  if ((g_wsta_warning != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
    printf("<wsta>[warning]%s(): %d  -> wsta idle time start\r\n","_wsta_idle_timer_handle",0x301);
  }
  local_30 = FUN_00408340(300,0,_wsta_idle_timer_handle,0,0,"_wsta_idle_timer_handle",0x310);
  if (((local_30 == -1) && (g_wsta_error != 0)) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
    printf("<wsta>[error]%s(): %d  -> uac_timer_add() fail!\r\n","_wsta_idle_timer_handle",0x313);
  }
  FUN_0051ad88(&local_88);
  FUN_004082d0(DAT_007cc6bc,0xffffffff);
  if (DAT_007cc710 == 0) {
    DAT_007cc710 = FUN_004081b0(&DAT_007cc6d8);
  }
  iVar5 = 0x186a1;
  iVar1 = DAT_007cc710;
  while (iVar2 = iVar1, iVar2 != 0) {
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) goto LAB_0063e33c;
    iVar1 = FUN_00408680(iVar2);
    if ((*(uint *)(iVar2 + 0x58) & 1) == 0) {
      if ((g_wsta_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("<wsta>[debug]%s(): %d  -> ap not support rssi inform!\r\n","_wsta_idle_timer_handle"
               ,0x324);
      }
    }
    else {
      FUN_00407e70();
      uVar3 = *(uint *)(iVar2 + 0x2c);
      if (extraout_v1 < uVar3) {
        uVar3 = ~uVar3;
      }
      else {
        uVar3 = -uVar3;
      }
      if (0x388 < extraout_v1 + uVar3) {
        iVar1 = wsta_calloc(1,0x80,"_wsta_idle_timer_handle",0x32c);
        if (iVar1 != 0) {
          memcpy((void *)(iVar1 + 0x18),(void *)(iVar2 + 0xc),0x68);
          FUN_004086b0(&local_88,iVar1 + 0xc);
        }
        __s1 = (void *)(iVar2 + 0x5c);
        iVar1 = wsta_db_get_mac_entry_by_peer(__s1,auStack_68);
        if (iVar1 == 0) {
          uVar3 = 0;
LAB_0063e4a4:
          while (uVar3 < local_56) {
            iVar1 = memcmp(__s1,auStack_52 + uVar3 * 0xc,6);
            if ((iVar1 == 0) ||
               (iVar1 = FUN_00407fa0(DAT_007cc6cc,auStack_52 + uVar3 * 0xc), iVar1 == 0)) {
              uVar3 = uVar3 + 1 & 0xff;
            }
            else {
              iVar4 = wsta_calloc(1,0x80,"_wsta_idle_timer_handle",0x33c);
              if (iVar4 != 0) {
                memcpy((void *)(iVar4 + 0x18),(void *)(iVar1 + 0x18),0x68);
                FUN_004086b0(&local_88,iVar4 + 0xc);
              }
              _wsta_free_entry(iVar1);
              uVar3 = uVar3 + 1 & 0xff;
            }
          }
          iVar1 = memcmp(__s1,auStack_5c,6);
          if ((iVar1 != 0) && (iVar1 = FUN_00407fa0(DAT_007cc6cc,auStack_5c), iVar1 != 0)) {
            iVar4 = wsta_calloc(1,0x80,"_wsta_idle_timer_handle",0x34b);
            if (iVar4 != 0) {
              memcpy((void *)(iVar4 + 0x18),(void *)(iVar1 + 0x18),0x68);
              FUN_004086b0(&local_88,iVar4 + 0xc);
            }
            _wsta_free_entry(iVar1);
          }
          wsta_db_free_mlo_mac_entry(auStack_68);
        }
        else {
          iVar1 = wsta_db_get_mac_entry_by_mld(__s1,auStack_68);
          uVar3 = 0;
          if (iVar1 == 0) goto LAB_0063e4a4;
        }
        iVar1 = FUN_00408680(iVar2);
        _wsta_free_entry(iVar2 + -0xc);
      }
    }
  }
  iVar2 = FUN_004081b0(&DAT_007cc6d8);
LAB_0063e33c:
  DAT_007cc710 = iVar2;
  DAT_007cc70c = local_30;
  FUN_00407f30(DAT_007cc6bc);
  iVar5 = FUN_004081b0(&local_88);
  while (iVar5 != 0) {
    iVar1 = FUN_00408680(iVar5);
    snprintf((char *)&local_7c,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(iVar5 + 0x5c),
             (uint)*(byte *)(iVar5 + 0x5d),(uint)*(byte *)(iVar5 + 0x5e),
             (uint)*(byte *)(iVar5 + 0x5f),(uint)*(byte *)(iVar5 + 0x60),
             (uint)*(byte *)(iVar5 + 0x61));
    loggerk_reg(0x5b,0x3a9b,1,&local_7c,0);
    _uac_wstation_do_event(1,iVar5 + -0xc);
    FUN_00408500(iVar5);
    wsta_free(iVar5 + -0xc);
    iVar5 = iVar1;
  }
  return;
}

