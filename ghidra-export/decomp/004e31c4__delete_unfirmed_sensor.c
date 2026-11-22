// func _delete_unfirmed_sensor @ 004e31c4 size=84

undefined4 _delete_unfirmed_sensor(int param_1,undefined4 *param_2)

{
  if (*(int *)(param_1 + 0x3c) == 0) {
    apmngr_ap_delete(param_1 + 0x10,1,0,0,0);
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 1;
    }
  }
  return 0;
}

