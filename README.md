# Circle 1.3_Get_next_line
## Program a function that returns the next line read from a file descriptor
### Objectives<br>
🎯Understand Static Variables <br>
🎯What is File Descriptor? <br>
🎯Memory Management: Malloc, Free, and Protection <br>
🎯Buffersize Macro<br>
🎯Read, Open function<br>

Achieved Score 💯

<blockquote> :memo: when you read data from fd upto the buffersize that you set, you need to think about 2 cases. <br>
1. newline character is found within the buffersize <br>
2. newline character isn't found -> we need to allocate more memory for the next read operation until newline character occurs <br>
