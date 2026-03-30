@startuml
' =========================
' FUNCIONES DE PERTENENCIA
' =========================
abstract class MembershipFunction {
    + double compute(double x)
}

class TriangularMF {
    - double a
    - double b
    - double c
    + compute(double x)
}

class TrapezoidalMF {
    - double a
    - double b
    - double c
    - double d
    + compute(double x)
}

MembershipFunction <|-- TriangularMF
MembershipFunction <|-- TrapezoidalMF

' =========================
' FUZZY SET
' =========================
class FuzzySet {
    - string name
    - MembershipFunction* mf
    + double getMembership(double x)
}

FuzzySet --> MembershipFunction

' =========================
' VARIABLE LINGÜÍSTICA
' =========================
class LinguisticVariable {
    - string name
    - double minRange
    - double maxRange
    - vector<FuzzySet> sets
    + addSet(FuzzySet set)
    + fuzzify(double x) : map<string, double>
}

LinguisticVariable --> FuzzySet

' =========================
' FUZZY RULE
' =========================
class FuzzyRule {
    - vector<pair<LinguisticVariable*, string>> antecedents
    - pair<LinguisticVariable*, string> consequent
    + evaluate(map<string, double> inputs) : double
}

' =========================
' INFERENCE ENGINE
' =========================
class InferenceEngine {
    - vector<FuzzyRule> rules
    + evaluate(map<string, double> inputs) : map<string, double>
}

InferenceEngine --> FuzzyRule

' =========================
' DEFUZZIFIER
' =========================
abstract class Defuzzifier {
    + double defuzzify(map<double, double> outputMF)
}

class CentroidDefuzzifier {
    + defuzzify(map<double, double> outputMF)
}

Defuzzifier <|-- CentroidDefuzzifier

' =========================
' SISTEMA COMPLETO
' =========================
class FuzzySystem {
    - vector<LinguisticVariable> inputs
    - LinguisticVariable output
    - InferenceEngine engine
    - Defuzzifier* defuzzifier
    + double evaluate(map<string, double> inputs)
}

FuzzySystem --> LinguisticVariable
FuzzySystem --> InferenceEngine
FuzzySystem --> Defuzzifier
@enduml