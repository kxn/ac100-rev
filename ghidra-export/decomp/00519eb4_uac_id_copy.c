// func uac_id_copy @ 00519eb4 size=208

void uac_id_copy(undefined4 *param_1,undefined4 *param_2)

{
  if ((param_1 != (undefined4 *)0x0) && (param_2 != (undefined4 *)0x0)) {
    if (param_1[4] == param_2[4]) {
      param_1[2] = param_2[2];
      param_1[3] = param_2[3];
      param_1[5] = param_2[5];
      memcpy((void *)*param_1,(void *)*param_2,param_1[4] << 2);
      memcpy((void *)param_1[1],(void *)param_2[1],(param_1[4] + 0x1f >> 5) << 2);
      return;
    }
    puts("uid_dst\'s size is not equal to uid_src\'s size");
    return;
  }
  return;
}

