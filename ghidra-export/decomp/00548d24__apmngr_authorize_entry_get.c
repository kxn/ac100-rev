// func _apmngr_authorize_entry_get @ 00548d24 size=456

undefined4 _apmngr_authorize_entry_get(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined1 auStack_90 [128];
  
  memset(auStack_90,0,0x80);
  if (*param_2 < 1) {
    if (param_2[1] < 1) {
      return 0;
    }
    if (((*(ushort *)(param_1 + 0x28) & 5) != 0) || ((*(ushort *)(param_1 + 0x28) & 2) != 0)) {
      iVar1 = json_object_new_object();
      if (iVar1 != 0) {
        mac2str(param_1 + 0x48,auStack_90,0x80);
        uVar2 = json_object_new_int(*(undefined2 *)(param_1 + 0x10));
        json_object_object_add(iVar1,"entry_id",uVar2);
        uVar2 = json_object_new_string(param_1 + 0x4e);
        json_object_object_add(iVar1,"entry_name",uVar2);
        uVar2 = json_object_new_int(*(undefined4 *)(param_1 + 0x40));
        json_object_object_add(iVar1,"model_id",uVar2);
        uVar2 = json_object_new_string(auStack_90);
        json_object_object_add(iVar1,"mac",uVar2);
        if ((*(ushort *)(param_1 + 0x28) & 1) == 0) {
          if ((*(ushort *)(param_1 + 0x28) & 4) == 0) {
            pcVar3 = "accepted";
          }
          else {
            pcVar3 = "rejected";
          }
        }
        else {
          pcVar3 = "default";
        }
        uVar2 = json_object_new_string(pcVar3);
        json_object_object_add(iVar1,"status",uVar2);
        json_object_array_add(param_2[5],iVar1);
        param_2[1] = param_2[1] + -1;
        param_2[2] = param_2[2] + 1;
        return 0;
      }
      if (apmngr_err_switch != '\0') {
        iVar1 = is_target_debug_ap();
        if (iVar1 != 0) {
          printf("[APMNGR_ERROR]%s()/%d Create json object failed when tranverse ap list.\n",
                 "_apmngr_authorize_entry_get",0x712);
          return 1;
        }
        return 1;
      }
      return 1;
    }
  }
  *param_2 = *param_2 + -1;
  return 0;
}

