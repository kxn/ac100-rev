; func capwap_dtls_cfg_destroy @ 0x00597864 size=0x2c
  597864:	27bdffe0 	addiu	sp,sp,-32
  597868:	afbf001c 	sw	ra,28(sp)
  59786c:	afb00018 	sw	s0,24(sp)
  597870:	00808021 	move	s0,a0
  597874:	0c101de4 	jal	0x407790
  597878:	8c840000 	lw	a0,0(a0)
  59787c:	02002021 	move	a0,s0
  597880:	8fbf001c 	lw	ra,28(sp)
  597884:	8fb00018 	lw	s0,24(sp)
  597888:	08101f7c 	j	0x407df0
  59788c:	27bd0020 	addiu	sp,sp,32
