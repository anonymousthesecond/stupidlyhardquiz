#include <stdio.h>
#include <string.h>

int main() {
    int score = 0;

    // Math Questions and answers
    char mathQuestions[][350] = {
        "1. Linear Algebra (Basis and Dimensionality): Given a matrix A, how can you determine if the set of its columns forms a basis for its column space? Explain your reasoning.",
        "2. Calculus (Multivariable Integration): If F(x, y, z) is a continuously differentiable function in a solid region R, what does the divergence theorem relate to the surface integral over the boundary of R of F • n dA and the triple integral over R of div(F) dV? (n is the outward unit normal vector to the boundary)",
        "3. Real Analysis (Infinite Series): Which of the following series is guaranteed to converge uniformly on the interval [-1, 1]?",
        "4. Number Theory (Modular Arithmetic): In modular arithmetic modulo 7, what is the multiplicative inverse of 3?",
        "5. Combinatorics (Generating Functions): What is the coefficient of x^3 in the generating function for the number of ways to arrange 5 distinct balls in 3 distinguishable boxes, allowing for empty boxes?"
    };
    char mathChoices[][4][250] = {
        {"A. Check if the columns are linearly independent.", "B. Calculate the determinant of A.", "C. Verify if the columns span the column space.", "D. All of the above"},
        {"A. The line integral of F along a closed curve.", "B. The change in the scalar field F over the boundary.", "C. The volume integral of the gradient of F.", "D. The area enclosed by the surface integral"},
        {"A. Σ (n^2 / (2^n)) (n starts from 1 to infinity)", "B. Σ (sin(nx) / n) (n starts from 1 to infinity) (x is a real number)", "C. Σ (1 / n^(1/2)) (n starts from 1 to infinity)", "D. Σ (e^(-nx)) (n starts from 1 to infinity) (x is a positive real number)"},
        {"A. 2", "B. 4", "C. 5", "D. 6"},
        {"A. 3", "B. 5", "C. 10", "D. 15"}
    };
    int mathAnswers[] = {2, 1, 2, 0, 0};  // Index of the correct answer for each math question

    // Physics Questions and answers
    char physicsQuestions[][350] = {
        "6. Special Relativity: An observer on Earth measures a spaceship to be 10 meters long when it's at rest. If the spaceship is traveling at 0.8c (80% the speed of light) relative to Earth, what is the measured length of the spaceship according to the observer on Earth?",
        "7. Quantum Mechanics: In the double-slit experiment, what happens to the interference pattern if a single photon is sent through the slits at a time?",
        "8. Thermodynamics: What is the entropy change (ΔS) for a reversible isothermal process (constant temperature)?",
        "9. Electromagnetism: What is the force experienced by a charged particle moving in a magnetic field?",
        "10. Fluid Mechanics: What is the relationship between the pressure (P), density (ρ), and flow velocity (v) in an incompressible fluid described by Bernoulli's equation?"
    };
    char physicsChoices[][4][250] = {
        {"A. 10 meters", "B. Shorter than 10 meters", "C. Longer than 10 meters", "D. It depends on the angle of observation."},
        {"A. The interference pattern disappears completely.", "B. The interference pattern remains the same as with many photons.", "C. The interference pattern becomes clearer.", "D. The interference pattern appears but with a granular, probabilistic distribution."},
        {"A. ΔS > 0", "B. ΔS < 0", "C. ΔS = 0", "D. ΔS depends on the specific system."},
        {"A. The force is always zero.", "B. The force is always in the direction of the magnetic field.", "C. The force is always perpendicular to both the magnetic field and the particle's velocity.", "D. The force depends on the charge of the particle only."},
        {"A. P + ½ρv^2 = constant", "B. P - ½ρv^2 = constant", "C. P * ρv = constant", "D. P / ρv = constant"}
    };
    int physicsAnswers[] = {1, 3, 2, 2, 0};  // Index of the correct answer for each physics question

    // Programming Questions and answers
    char progQuestions[][250] = {
        "11. Closures: Consider the following code:\n\n\
function outerFunction() {\n\
  let outerVar = 'outer';\n\
  function innerFunction() {\n\
    console.log(outerVar);\n\
  }\n\
  return innerFunction;\n\
}\n\
\n\
const inner = outerFunction();\n\
inner();\n\n\
What will be printed to the console?",
        "12. Prototypal Inheritance: How can you extend the functionality of an existing object in JavaScript using prototypal inheritance?",
        "13. Asynchronous Programming (Promises): How do Promises handle errors in asynchronous operations in JavaScript?",
        "14. Functional Programming (Higher-Order Functions): What is the purpose of a higher-order function in JavaScript?",
        "15. Error Handling (Try...Catch): How does a try...catch block work in JavaScript for error handling?",
        "16. The DOM (Document Object Model): How can you dynamically add a new element to the DOM in JavaScript?"
    };
    char progChoices[][4][250] = {
        {"A. ReferenceError: outerVar is not defined", "B. undefined", "C. 'outer'", "D. 'inner'"},
        {"A. By directly modifying the object's properties", "B. By creating a new object and setting its prototype to the existing object", "C. By using the `extends` keyword", "D. By using the `Object.assign` method"},
        {"A. Errors are silently ignored.", "B. The Promise object rejects with an error reason.", "C. The Promise object resolves with a null value.", "D. You need to manually check for errors using a try-catch block."},
        {"A. To perform calculations on numbers.", "B. To take functions as arguments and/or return functions as results.", "C. To access DOM elements.", "D. To create objects with properties and methods."},
        {"A. It retries the code in the try block if an error occurs.", "B. It executes the code in the try block and catches any errors that occur, allowing you to handle them in the catch block.", "C. It prevents any errors from occurring.", "D. It allows you to define custom error messages."},
        {"A. By directly modifying the HTML code.", "B. Using the `createElement` method to create a new element and then using methods like `appendChild` to add it to the existing DOM structure.", "C. By injecting HTML strings into the document.", "D. There is no way to dynamically add elements in JavaScript."}
    };
    int progAnswers[] = {2, 1, 1, 1, 1, 1};  // Index of the correct answer for each programming question

    // Display and process math questions
    for (int i = 0; i < 5; i++) {
        printf("\n%s\n", mathQuestions[i]);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", mathChoices[i][j]);
        }

        char userChoice[2];
        do {
            printf("Enter your choice (A/B/C/D): ");
            scanf("%1s", userChoice);
        } while (userChoice[0] < 'A' || userChoice[0] > 'D');

        // Convert user's choice to index (A->0, B->1, C->2, D->3)
        int choiceIndex = userChoice[0] - 'A';

        if (choiceIndex == mathAnswers[i]) {
            printf("Correct!\n");
            score++;
        } else {
            printf("No, that's wrong. The correct answer is %c.\n", 'A' + mathAnswers[i]);
        }
    }

    // Display and process physics questions
    for (int i = 0; i < 5; i++) {
        printf("\n%s\n", physicsQuestions[i]);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", physicsChoices[i][j]);
        }

        char userChoice[2];
        do {
            printf("Enter your choice (A/B/C/D): ");
            scanf("%1s", userChoice);
        } while (userChoice[0] < 'A' || userChoice[0] > 'D');

        // Convert user's choice to index (A->0, B->1, C->2, D->3)
        int choiceIndex = userChoice[0] - 'A';

        if (choiceIndex == physicsAnswers[i]) {
            printf("Correct!\n");
            score++;
        } else {
            printf("No, that's wrong. The correct answer is %c.\n", 'A' + physicsAnswers[i]);
        }
    }

    // Display and process programming questions
    for (int i = 0; i < 6; i++) {
        printf("\n%s\n", progQuestions[i]);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", progChoices[i][j]);
        }

        char userChoice[2];
        do {
            printf("Enter your choice (A/B/C/D): ");
            scanf("%1s", userChoice);
        } while (userChoice[0] < 'A' || userChoice[0] > 'D');

        // Convert user's choice to index (A->0, B->1, C->2, D->3)
        int choiceIndex = userChoice[0] - 'A';

        if (choiceIndex == progAnswers[i]) {
            printf("Correct!\n");
            score++;
        } else {
            printf("No, that's wrong. The correct answer is %c.\n", 'A' + progAnswers[i]);
        }
    }

    // Display final score
    printf("\nQuiz completed! Your score: %d/16\n", score);

    return 0;
}

