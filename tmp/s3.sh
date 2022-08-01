files=$(s3cmd ls s3://bertrust | awk '{system("basename " $4)}')

# download files

for file in $files; do
 wget <http://bertrust.s3.amazonaws.com/$file>
done

# upload files

for file in $files; do
 s3cmd put $file s3://bertrust
done

# recursively set acl of the files in the bucket to public accessible

s3cmd setacl -Pr s3://bertrust
