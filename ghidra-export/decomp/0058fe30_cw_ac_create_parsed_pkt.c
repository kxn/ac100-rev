// func cw_ac_create_parsed_pkt @ 0058fe30 size=240

undefined1 * cw_ac_create_parsed_pkt(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  puVar2 = (undefined1 *)FUN_00408450(0x38,0x108);
  if (puVar2 == (undefined1 *)0x0) {
    if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[CW_ERROR]%32s():%4d malloc parsed pkt failed\n","cw_ac_create_parsed_pkt",0x10b);
    }
  }
  else {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 2;
    uVar3 = *(undefined4 *)(param_1 + 0xa0);
    puVar2[6] = 0;
    puVar2[7] = 0;
    puVar2[3] = (char)uVar3;
    puVar2[8] = 0;
    puVar2[4] = 1;
    puVar2[5] = 1;
    puVar2[9] = 0;
    puVar2[10] = 0;
    puVar2[0xb] = 0;
    *(undefined2 *)(puVar2 + 0xc) = 0;
    *(undefined2 *)(puVar2 + 0xe) = 0;
    *(undefined4 *)(puVar2 + 0x10) = param_2;
    uVar1 = *(undefined1 *)(param_1 + 0xa4);
    puVar2[0x18] = 0;
    puVar2[0x14] = uVar1;
    *(undefined2 *)(puVar2 + 0x16) = 3;
    FUN_0051ad88(puVar2 + 0x1c);
  }
  return puVar2;
}

