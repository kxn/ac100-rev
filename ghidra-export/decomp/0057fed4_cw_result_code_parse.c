// func cw_result_code_parse @ 0057fed4 size=300

undefined4 cw_result_code_parse(int param_1,int param_2)

{
  ushort uVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar1 = *(ushort *)(param_1 + 6);
  puVar2 = (uint *)FUN_00408450(4,0x8c);
  if (puVar2 == (uint *)0x0) {
    uVar4 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_result_code_parse",0x8f);
    }
  }
  else {
    *(undefined1 *)puVar2 = 0;
    *(undefined1 *)((int)puVar2 + 1) = 0;
    *(undefined1 *)((int)puVar2 + 2) = 0;
    *(undefined1 *)((int)puVar2 + 3) = 0;
    uVar3 = cw_protocol_retrieve32(param_1);
    *puVar2 = uVar3;
    if (uVar3 < 0x19) {
      *(uint **)(param_2 + 0x10) = puVar2;
      uVar4 = 0xffffffff;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
        uVar4 = 0;
      }
    }
    else {
      if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
        printf("[CW_ERROR]%32s():%4d result code(%d) is wrong\n","cw_result_code_parse",0x98,*puVar2
              );
      }
      FUN_00407df0(puVar2);
      uVar4 = 0xffffffff;
    }
  }
  return uVar4;
}

