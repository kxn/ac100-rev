// func rdmngr_uninit @ 0061830c size=60

undefined4 rdmngr_uninit(void)

{
  if (l_working_channel_mutex != 0) {
    FUN_00408360();
    l_working_channel_mutex = 0;
  }
  return 0;
}

