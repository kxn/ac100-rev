; func _uac_json_object_to_integer @ 0x0045e7d0 size=0xec
  45e7d0:	27bdffd8 	addiu	sp,sp,-40
  45e7d4:	afb20020 	sw	s2,32(sp)
  45e7d8:	00a09021 	move	s2,a1
  45e7dc:	afb1001c 	sw	s1,28(sp)
  45e7e0:	00008821 	move	s1,zero
  45e7e4:	afb00018 	sw	s0,24(sp)
  45e7e8:	00808021 	move	s0,a0
  45e7ec:	1080000b 	beqz	a0,0x45e81c
  45e7f0:	afbf0024 	sw	ra,36(sp)
  45e7f4:	0c101bfc 	jal	0x406ff0
  45e7f8:	00000000 	nop
  45e7fc:	24030003 	li	v1,3
  45e800:	1043000d 	beq	v0,v1,0x45e838
  45e804:	00000000 	nop
  45e808:	0c101bfc 	jal	0x406ff0
  45e80c:	02002021 	move	a0,s0
  45e810:	24030002 	li	v1,2
  45e814:	10430008 	beq	v0,v1,0x45e838
  45e818:	00000000 	nop
  45e81c:	8fbf0024 	lw	ra,36(sp)
  45e820:	8fb00018 	lw	s0,24(sp)
  45e824:	ae510000 	sw	s1,0(s2)
  45e828:	8fb20020 	lw	s2,32(sp)
  45e82c:	8fb1001c 	lw	s1,28(sp)
  45e830:	03e00008 	jr	ra
  45e834:	27bd0028 	addiu	sp,sp,40
  45e838:	0c101bfc 	jal	0x406ff0
  45e83c:	02002021 	move	a0,s0
  45e840:	24030003 	li	v1,3
  45e844:	10430012 	beq	v0,v1,0x45e890
  45e848:	02002021 	move	a0,s0
  45e84c:	0c101bfc 	jal	0x406ff0
  45e850:	00000000 	nop
  45e854:	24030002 	li	v1,2
  45e858:	10430011 	beq	v0,v1,0x45e8a0
  45e85c:	00000000 	nop
  45e860:	3c020075 	lui	v0,0x75
  45e864:	8c42be90 	lw	v0,-16752(v0)
  45e868:	1040ffec 	beqz	v0,0x45e81c
  45e86c:	2411ffff 	li	s1,-1
  45e870:	3c040067 	lui	a0,0x67
  45e874:	3c050069 	lui	a1,0x69
  45e878:	24846a80 	addiu	a0,a0,27264
  45e87c:	24a5b41c 	addiu	a1,a1,-19428
  45e880:	0c101b74 	jal	0x406dd0
  45e884:	240600e1 	li	a2,225
  45e888:	08117a08 	j	0x45e820
  45e88c:	8fbf0024 	lw	ra,36(sp)
  45e890:	0c101d10 	jal	0x407440
  45e894:	00000000 	nop
  45e898:	08117a07 	j	0x45e81c
  45e89c:	00408821 	move	s1,v0
  45e8a0:	0c101c54 	jal	0x407150
  45e8a4:	02002021 	move	a0,s0
  45e8a8:	00602821 	move	a1,v1
  45e8ac:	0c101f0c 	jal	0x407c30
  45e8b0:	00402021 	move	a0,v0
  45e8b4:	08117a07 	j	0x45e81c
  45e8b8:	00408821 	move	s1,v0
