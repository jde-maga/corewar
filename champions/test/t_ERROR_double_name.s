.name "kernel" 
.name "kernel" 
.comment "kernel"

label:
ld %1,r3
live %1
live %:label
ld:
ld :ld,r4
ld :ld, r4

#TEST# COMMENT
label1:
live %4 #coment#
live  %:label1 ;coment; %4
