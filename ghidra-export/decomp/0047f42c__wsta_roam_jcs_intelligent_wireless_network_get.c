// func _wsta_roam_jcs_intelligent_wireless_network_get @ 0047f42c size=172

void _wsta_roam_jcs_intelligent_wireless_network_get(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 uStack_38;
  byte local_37;
  
  memset(&uStack_38,0,0x22);
  iVar1 = wsta_roam_db_cfg_get(&uStack_38);
  if (iVar1 != -1) {
    if (local_37 == 0) {
      iVar1 = -1;
    }
    else if (local_37 < 3) {
      if (iVar1 == 0) {
        uVar2 = json_object_new_int();
        json_object_object_add(param_2,"real_mode",uVar2);
      }
    }
    else {
      iVar1 = -1;
    }
  }
  uVar2 = json_object_new_int(iVar1);
  json_object_object_add(param_2,"result",uVar2);
  return;
}

