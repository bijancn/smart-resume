type summary = {content: string};

type date = {repr: string};

type person = {
  age: int,
  name: string,
};

type name = {
  firstName: string,
  middleName: string,
  lastName: string,
};

type employment = {
  startDate: date,
  endDate: date,
  company: string,
  website: string,
  position: string,
  summary: string,
  highlights: list(string),
};

type education = {
  institution: string,
  area: string,
  studyType: string,
  startDate: string,
  endDate: string,
  grade: string,
};

type skillLevel =
  | Beginner
  | Intermediate
  | Expert;

type skill = {
  name: string,
  level: skillLevel,
};

type languageFluency =
  | NativeSpeaker
  | Proficient // C2
  | Advanced // C1
  | UpperIntermediate // B2
  | Intermediate // B1
  | Elementary // A2
  | Beginner; // A1

type language = {
  language: string,
  fluency: languageFluency,
};

type publication = {title: string};
type resumeData = {
  name,
  headline: string,
  location: string,
  summary,
  socials: list(string), // TODO: Make it a Map from icon to URL
  work: list(employment),
  education: list(education),
  publications: list(publication),
  skills: list(skill),
  languages: list(language),
};