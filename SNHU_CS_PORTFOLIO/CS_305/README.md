# CS 305
## Module 8 Journal and Repository Entry

### Briefly summarize your client, Artemis Financial, and their software requirements. Who was the client? What issue did they want you to address? 
Artemis Financial is a financial services company that had concerns about the security of their software systems. They wanted us to assess their software for vulnerabilities and implement measures to improve security.

### What did you do very well when you found your client’s software security vulnerabilities? Why is it important to code securely? What value does software security add to a company’s overall wellbeing? 
I did a great job at identifying Artemis Financial's software security vulnerabilities by conducting a comprehensive assessment of their systems utilizing the Software Vulnerability Flowchart. Ensuring secure code is crucial because it mitigates the risk of data breaches, protects sensitive information, maintains customer trust, and avoids financial losses resulting from cyberattacks. Software security adds significant value to a company's overall wellbeing by safeguarding its assets, reputation, and operations from potential threats.

### What part of the vulnerability assessment was challenging or helpful to you? 
One challenging aspect of the vulnerability assessment was identifying hidden or obscure vulnerabilities that could potentially be exploited by malicious actors. In addition, the process of using static analysis with the Maven Dependency Check tool, and silencing false positives, was very helpful as it could be applied to any Maven codebase.

### How did you increase layers of security? In the future, what would you use to assess vulnerabilities and decide which mitigation techniques to use? 
To increase layers of security, we implemented various measures such as TLs on the web server for encrypting the traffic, and employing a hash to encrypt the stored user data. In the future, we would employ advanced vulnerability scanning tools and threat modeling techniques to assess further vulnerabilities.

### How did you make certain the code and software application were functional and secure? After refactoring the code, how did you check to see whether you introduced new vulnerabilities? 
To ensure the code and software application were both functional and secure, we conducted both static analysis and functional analysis of the codebase. Through the functional analysis, we added dependencies to obfuscate data further. After refactoring the code, we performed additional static anlysis to ensure our new dependencies didn't introduce new vulnerabilities.

### What resources, tools, or coding practices did you use that might be helpful in future assignments or tasks? 
We utilized a range of tools and coding practices throughout the project, including static analysis tools, functional anlysis, encryption algorithms, secure TLS certification, and best practices such as input validation and output encoding. These resources and practices will be invaluable for future assignments or tasks involving software security.

### Employers sometimes ask for examples of work that you have successfully completed to show your skills, knowledge, and experience. What might you show future employers from this assignment?
For future employers, I would showcase the, highlighting the comprehensive vulnerability assessment, effective implementation of security measures, and thorough testing processes that contributed to enhancing the security of Artemis Financial's software systems.

