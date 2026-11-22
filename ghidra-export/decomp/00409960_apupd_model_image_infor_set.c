// func apupd_model_image_infor_set @ 00409960 size=148

undefined4 apupd_model_image_infor_set(int param_1,int param_2,undefined4 param_3,void *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_1 == 0) || (param_2 == 0)) || (param_4 == (void *)0x0)) {
    uVar2 = 0xffffffff;
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_model_image_infor_set",0x5a4);
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x1ac) = param_3;
    uVar2 = 0;
    *(int *)(param_1 + 0x1b0) = param_2;
    memcpy((void *)(param_1 + 0x1c4),param_4,0x10);
  }
  return uVar2;
}

